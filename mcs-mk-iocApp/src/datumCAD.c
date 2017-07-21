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
 *      pcad->a = Which axis to datum              AZ/EL/BOTH   (STRING).
 *      pcad->b = Az Mechanism 
 *			SWITCH
 *			HEAD1
 *			HEAD2
 *			HEAD3
 *			HEAD4
 *      pcad->c = El Mechanism 
 *			SWITCH
 *			HEAD1
 *			HEAD2
 *      pcad->d = Current Debug Level              0/1          (STRING).
 *      pcad->e = State of Azimuth axis            0/1/2/3      (STRING).
 *      pcad->f = State of Elevation axis          0/1/2/3      (STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = Mask for sequence record                   (LONG).
 *                      1 = Azimuth
 *                      2 = Elevation
 *                      3 = Both
 *      pcad->valb = Az Mechanism				(LONG).
 *			SWITCH
 *			HEAD1
 *			HEAD2
 *			HEAD3
 *			HEAD4
 *      pcad->valc = El Mechanism                               (LONG).
 *			SWITCH
 *			HEAD1
 *			HEAD2
 *      pcad->vald = Set Az. command to MCS_DATUM               (LONG).
 *      pcad->vale = Set El. command to MCS_DATUM               (LONG).
 */

long datumCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long debug;
  long azState;
  long elState;
  char axis[MAX_STRING_SIZE];
  char mech[MAX_STRING_SIZE];
  long error;

  debug    = atol( (char *)pcad->d );
  azState  = atol( (char *)pcad->e );
  elState  = atol( (char *)pcad->f );
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
      strcpy( (char *)pcad->b, "SWITCH");
      strcpy( (char *)pcad->c, "SWITCH");
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
      {
        if( !strcmp(axis, "AZ") )
        {
          *(long *)pcad->vala = 1;
          if( (azState == MCS_BRAKED) || (azState == MCS_STATIONARY) )
          {
            *(long *)pcad->vald = MCS_DATUM;
            ret = CAD_ACCEPT;
            if( debug)
              printf("datumCAD: datum az\n");
          }
          else
          {
            strcpy( pcad->mess, "Azimuth axis must be stationary" );
            ret = CAD_REJECT;
          }
        }
        else if( !strcmp(axis, "EL") )
        {
          *(long *)pcad->vala = 2;
          if( (elState == MCS_BRAKED) || (elState == MCS_STATIONARY) )
          {
            *(long *)pcad->vale = MCS_DATUM;
            ret = CAD_ACCEPT;
            if( debug)
              printf("datumCAD: datum el\n");
          }
          else
          {
            strcpy( pcad->mess, "Elevation axis must be stationary" );
            ret = CAD_REJECT;
          }
        }
        else if( !strcmp(axis, "BOTH") )
        {
          *(long *)pcad->vala = 3;
          if( (azState == MCS_BRAKED) || (azState == MCS_STATIONARY) )
          {
            *(long *)pcad->vald = MCS_DATUM;
            ret = CAD_ACCEPT;
            if( debug)
              printf("datumCAD: datum az\n");
          }
          else
          {
            strcpy( pcad->mess, "Azimuth axis must be stationary" );
            ret = CAD_REJECT;
          }

          if( ret == CAD_ACCEPT )
          {
            if( (elState == MCS_BRAKED) || (elState == MCS_STATIONARY) )
            {
              *(long *)pcad->vale = MCS_DATUM;
              ret = CAD_ACCEPT;
              if( debug)
                printf("datumCAD: datum el\n");
            }
            else
            {
              strcpy( pcad->mess, "Elevation axis must be stationary" );
              ret = CAD_REJECT;
            }
          }
        }
      }

      if( ret == CAD_ACCEPT )
      {
        error = check_string( pcad->b, mech, MAX_STRING_SIZE, 1 );
        if( error == ALL_BLANKS )
        {
          sprintf( pcad->mess, "The Azimuth mechanism field is blank" );
          ret = CAD_REJECT;
        }
        else if( error == TOO_LONG )
        {
          sprintf( pcad->mess, "The Azimuth mechanism field is too long" );
          ret = CAD_REJECT;
        }
        else if( strcmp(mech, "SWITCH") && strcmp(mech, "HEAD1") && strcmp(mech, "HEAD2") &&
                 strcmp(mech, "HEAD3")  && strcmp(mech, "HEAD4") )
        {
          sprintf( pcad->mess, "%s: Not a valid Az. mechanism", mech );
          ret = CAD_REJECT;
        }
        else
        {
          if( !strcmp(mech, "SWITCH") )
          {
            *(long *)pcad->valb = MCS_SWITCH;
            if( debug)
              printf("datumCAD: az - use SWITCH\n");
          }
          else if( !strcmp(mech, "HEAD1") )
          {
            *(long *)pcad->valb = MCS_HEAD_1;
            if( debug)
              printf("datumCAD: az - use HEAD1\n");
          }
          else if( !strcmp(mech, "HEAD2") )
          {
            *(long *)pcad->valb = MCS_HEAD_2;
            if( debug)
              printf("datumCAD: az - use HEAD2\n");
          }
          else if( !strcmp(mech, "HEAD3") )
          {
            *(long *)pcad->valb = MCS_HEAD_3;
            if( debug)
              printf("datumCAD: az - use HEAD3\n");
          }
          else if( !strcmp(mech, "HEAD4") )
          {
            *(long *)pcad->valb = MCS_HEAD_4;
            if( debug)
              printf("datumCAD: az - use HEAD4\n");
          }
          ret = CAD_ACCEPT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        error = check_string( pcad->c, mech, MAX_STRING_SIZE, 1 );
        if( error == ALL_BLANKS )
        {
          sprintf( pcad->mess, "The Elevation mechanism field is blank" );
          ret = CAD_REJECT;
        }
        else if( error == TOO_LONG )
        {
          sprintf( pcad->mess, "The Elevation mechanism field is too long" );
          ret = CAD_REJECT;
        }
        else if( strcmp(mech, "SWITCH") && strcmp(mech, "HEAD1") && strcmp(mech, "HEAD2") )
        {
          sprintf( pcad->mess, "%s: Not a valid El. mechanism", mech );
          ret = CAD_REJECT;
        }
        else
        {
          if( !strcmp(mech, "SWITCH") )
          {
            *(long *)pcad->valc = MCS_SWITCH;
            if( debug)
              printf("datumCAD: el - use SWITCH\n");
          }
          else if( !strcmp(mech, "HEAD1") )
          {
            *(long *)pcad->valc = MCS_HEAD_1;
            if( debug)
              printf("datumCAD: el - use HEAD1\n");
          }
          else if( !strcmp(mech, "HEAD2") )
          {
            *(long *)pcad->valc = MCS_HEAD_2;
            if( debug)
              printf("datumCAD: el - use HEAD2\n");
          }
          ret = CAD_ACCEPT;
        }
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
epicsRegisterFunction(datumCAD);
