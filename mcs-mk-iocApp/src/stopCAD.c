#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsPrint.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <cadRecord.h>
#include <cad.h>
#include <mcssir.h>
#include <mcscad.h>
#include <mcs.h>


/* 
 *  INPUTS:
 *      pcad->a = Which axis to stop               AZ/EL/BOTH   (STRING).
 *      pcad->b = Apply Brakes to Az               YES/NO       (STRING).
 *      pcad->c = Apply Brakes to El               YES/NO       (STRING).
 *      pcad->d = Current Debug Level              0/1          (STRING).
 *      pcad->e = State of Azimuth axis            0/1/2/3      (STRING).
 *      pcad->f = State of Elevation axis          0/1/2/3      (STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = Mask for sequence record.                  (LONG).
 *                   1 = Azimuth
 *                   2 = Elevation
 *                   3 = Both
 *                   4 = Neither
 *      pcad->valb = Mask for Azimuth.                          (LONG).
 *                   0 = No command
 *                   1 = Kill
 *                   2 = Open Loop
 *                   4 = Apply brakes
 *      pcad->valc = Mask for Elevation.                        (LONG).
 *                   0 = No command
 *                   1 = Kill
 *                   2 = Open Loop
 *                   4 = Apply brakes
 *      pcad->vald = Not used.
 *      pcad->vale = Set Az. command to MCS_STOP                (LONG).
 *      pcad->valf = Set El. command to MCS_STOP                (LONG).
 */

long stopCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long debug;
  long azState;
  long elState;
  char axis[MAX_STRING_SIZE];
  char brake[MAX_STRING_SIZE];
  long azBrake;
  long elBrake;
  long azMask;
  long elMask;
  long error;

  debug    = atol( (char *)pcad->d );
  azState  = atol( (char *)pcad->e );
  elState  = atol( (char *)pcad->f );
  azMask   = 0;
  elMask   = 0;
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 * Set default values on CLEAR.
 */
      strcpy( (char *)pcad->a, "BOTH");
      strcpy( (char *)pcad->b, "NO");
      strcpy( (char *)pcad->c, "NO");
      db_post_events( pcad, &pcad->a, 1 );
      db_post_events( pcad, &pcad->b, 1 );
      db_post_events( pcad, &pcad->c, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, axis, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "The Axis field is blank" );
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "The Axis field is too long" );
        ret = CAD_REJECT;
      }
      else if( strcmp(axis, "AZ") && strcmp(axis, "EL") && strcmp(axis, "BOTH") )
      {
        sprintf( pcad->mess, "%s: Not a valid axis", axis );
        ret = CAD_REJECT;
      }
      else
        ret = CAD_ACCEPT;

      if( ret == CAD_ACCEPT )
      {
        error = check_string( pcad->b, brake, MAX_STRING_SIZE, 1 );
        if( error == ALL_BLANKS )
        {
          sprintf( pcad->mess, "The Azimuth brake field is blank" );
          ret = CAD_REJECT;
        }
        else if( error == TOO_LONG )
        {
          sprintf( pcad->mess, "The Azimuth brake field is too long" );
          ret = CAD_REJECT;
        }
        else if( strcmp(brake, "YES") && strcmp(brake, "NO") )
        {
          sprintf( pcad->mess, "%s: Not a valid brake argument", brake );
          ret = CAD_REJECT;
        }
        else
        {
          if( !strcmp(brake, "YES") )
            azBrake = 1;
          else
            azBrake = 0;
          ret = CAD_ACCEPT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        error = check_string( pcad->c, brake, MAX_STRING_SIZE, 1 );
        if( error == ALL_BLANKS )
        {
          sprintf( pcad->mess, "The Elevation brake field is blank" );
          ret = CAD_REJECT;
        }
        else if( error == TOO_LONG )
        {
          sprintf( pcad->mess, "The Elevation brake field is too long" );
          ret = CAD_REJECT;
        }
        else if( strcmp(brake, "YES") && strcmp(brake, "NO") )
        {
          sprintf( pcad->mess, "%s: Not a valid brake argument", brake );
          ret = CAD_REJECT;
        }
        else
        {
          if( !strcmp(brake, "YES") )
            elBrake = 1;
          else
            elBrake = 0;
          ret = CAD_ACCEPT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        if( !strcmp(axis, "AZ") || !strcmp(axis, "BOTH") )
        {
          if( azBrake )                            /* If brakes to be applied */
          {
            if( azState == MCS_BRAKED )            /* Nothing to do           */
              *(long *)pcad->valb = 0;
            else if( (azState == MCS_STATIONARY) || 
                     (azState == MCS_SLEWING)    ||
                     (azState == MCS_TRACKING) )   /* Send Kill and Disassert */
            {
              azMask |= 1;
              azMask |= 4;
              *(long *)pcad->valb = azMask;
              if( debug )
                errlogPrintf("Send Kill and Disassert to Azimuth\n");
            }
          }
          else
          {
            if( (azState == MCS_SLEWING) || 
                (azState == MCS_TRACKING) )  /* Kill and then close the loop */
            {
              azMask |= 1;
              azMask |= 2;
              *(long *)pcad->valb = azMask;
              if( debug )
                errlogPrintf("Kill and then close the loop on Azimuth\n");
            }
            else                                   /* Nothing to do */
              *(long *)pcad->valb = azMask;
          }
        }

        if( !strcmp(axis, "EL") || !strcmp(axis, "BOTH") )
        {
          if( elBrake )
          {
            if( elState == MCS_BRAKED )            /* Nothing to do           */
              *(long *)pcad->valc = 0;
            else if( (elState == MCS_STATIONARY) ||
                     (elState == MCS_SLEWING)    ||
                     (elState == MCS_TRACKING) )   /* Send Kill and Disassert */
            {
              elMask |= 1;
              elMask |= 4;
              *(long *)pcad->valc = elMask;
              if( debug )
                errlogPrintf("Send Kill and Disassert to Elevation\n");
            }
          }
          else
          {
            if( (elState == MCS_SLEWING) || 
                (elState == MCS_TRACKING) ) /* Kill and then close the loop */
            {
              elMask |= 1;
              elMask |= 2;
              *(long *)pcad->valc = elMask;
              if( debug )
                errlogPrintf("Kill and then close the loop on Elevation\n");
            }
            else                                   /* Nothing to do */
              *(long *)pcad->valc = elMask;
          }
        }

        if( (*(long *)pcad->valb > 0) && (*(long *)pcad->valc == 0) )        /* Stop Az */
        {
          *(long *)pcad->vala = 1;
          if( debug )
            errlogPrintf("Stop Azimuth\n");
        }
        else if( (*(long *)pcad->valb == 0) && (*(long *)pcad->valc > 0) )   /* Stop El */
        {
          *(long *)pcad->vala = 2;
          if( debug )
            errlogPrintf("Stop Elevation\n");
        }
        else if( (*(long *)pcad->valb > 0) && (*(long *)pcad->valc > 0) )     /* Stop Az and El */
        {
          *(long *)pcad->vala = 3;
          if( debug )
            errlogPrintf("Stop Azimuth and Elevation\n");
        }
        else if( (*(long *)pcad->valb == 0) && (*(long *)pcad->valc == 0) )   /* Do nothing */
        {
          *(long *)pcad->vala = 4;
          if( debug )
            errlogPrintf("Do nothing\n");
        }

        *(long *)pcad->vale = MCS_STOP;
        *(long *)pcad->valf = MCS_STOP;
      }
      break;

    case menuDirectiveSTART:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveSTOP:
      ret = CAD_ACCEPT;
      break;

    default:
      break;
  }
  return ret;
}
epicsRegisterFunction(stopCAD);
