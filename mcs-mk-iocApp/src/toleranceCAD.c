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
#include <mcs.h>

#define MASK_NOCHANGE    0
#define MASK_POSCHANGE  11
#define MASK_VELCHANGE  13
#define MASK_BOTHCHANGE 15

/* 
 *  INPUTS:
 *      pcad->a = Position Error                        STRING -> DOUBLE
 *      pcad->b = Velocityi Error                       STRING -> DOUBLE
 *      pcad->c = Current Debug Level 0/1               STRING -> LONG
 *
 *  OUTPUTS:
 *      pcad->vala = Position Error                     (DOUBLE).
 *      pcad->valb = Velocity Error                     (DOUBLE).
 *      pcad->valc = Mask for sequence record           (LONG).
 */

long toleranceCAD( struct cadRecord *pcad )
{
  long   ret = 0;
  long   error;
  long   debug;
  long   posChange;
  long   velChange;
  double poserror = 0;
  double velerror = 0;

  debug = atol( (char *)pcad->c );

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 * Set default value on CLEAR.
 */
      strcpy( (char *)pcad->a, " ");
      strcpy( (char *)pcad->b, " ");
      db_post_events( pcad, &pcad->a, 1 );
      db_post_events( pcad, &pcad->b, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      /* First deal with position error */
      error = check_numeric( pcad->a );
      if( debug )
        errlogPrintf("toleranceCAD: error = %ld from check_numeric for position\n", error);
      if( error )
      {
        posChange = 0;
        if( error == ALL_BLANKS )  /* No change in position tolerance */
          ret = CAD_ACCEPT;
        else
        {
          sprintf(pcad->mess, "Position Error invalid");
          ret = CAD_REJECT;
        }
      }
      else
      {
        poserror = strtod( pcad->a, NULL );
        if( debug )
          errlogPrintf("toleranceCAD: Pos. Error = %f, Pos. Lower = %f, Pos. Upper = %f\n", 
                 poserror, POS_ERROR_LOWER, POS_ERROR_UPPER);
        if( poserror < POS_ERROR_LOWER )
        {
          sprintf(pcad->mess, "Position Error %6.3f below limit (%6.3f)", 
                  poserror, POS_ERROR_LOWER);
          ret = CAD_REJECT;
        }
        else if( poserror > POS_ERROR_UPPER )
        {
          sprintf(pcad->mess, "Position Error %6.3f above limit (%6.3f)", 
                  poserror, POS_ERROR_UPPER);
          ret = CAD_REJECT;
        }
        else
        {
          posChange = 1;
          ret       = CAD_ACCEPT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        /* Velocity error */
        error = check_numeric( pcad->b );
        if( debug )
          errlogPrintf("toleranceCAD: error = %ld from check_numeric for velocity\n", error);
        if( error )
        {
          velChange = 0;
          if( error == ALL_BLANKS )  /* No change in velocity tolerance */
            ret = CAD_ACCEPT;
          else
          {
            sprintf(pcad->mess, "Velocity Error invalid");
            ret = CAD_REJECT;
          }
        }
        else
        {
          velerror = strtod( pcad->b, NULL );
          if( debug )
            errlogPrintf("toleranceCAD: Vel. Error = %f, Vel. Lower = %f, Vel. Upper = %f\n", 
                   velerror, VEL_ERROR_LOWER, VEL_ERROR_UPPER);
          if( velerror < VEL_ERROR_LOWER )
          {
            sprintf(pcad->mess, "Velocity Error %6.3f below limit (%6.3f)", 
                    velerror, VEL_ERROR_LOWER);
            ret = CAD_REJECT;
          }
          else if( velerror > VEL_ERROR_UPPER )
          {
            sprintf(pcad->mess, "Velocity Error %6.3f above limit (%6.3f)", 
                    velerror, VEL_ERROR_UPPER);
            ret = CAD_REJECT;
          }
          else
          {
            velChange = 1;
            ret       = CAD_ACCEPT;
          }
        }
      }

      if( ret == CAD_ACCEPT )
      {
        if( posChange && velChange )
        {
          *(double *)pcad->vala = poserror;
          *(double *)pcad->valb = velerror;
          *(long *)pcad->valc   = MASK_BOTHCHANGE;
        }
        else if( posChange && !velChange )
        {
          *(double *)pcad->vala = poserror;
          *(long *)pcad->valc   = MASK_POSCHANGE;
        }
        else if( !posChange && velChange )
        {
          *(double *)pcad->valb = velerror;
          *(long *)pcad->valc   = MASK_VELCHANGE;
        }
        else if( !posChange && !velChange )
          *(long *)pcad->valc   = MASK_NOCHANGE;
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
epicsRegisterFunction(toleranceCAD);
