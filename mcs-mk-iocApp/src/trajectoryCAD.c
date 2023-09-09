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


/* 
 *  INPUTS:
 *      pcad->a = New trajectory calculation mode
 *                NO_ADJUST, VEL_ADJUST, FULL            (STRING).
 *      pcad->b = Current Debug Level  0/1               (STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = New trajectory calculation mode  0/1/2 (LONG).
 *
 */

long trajectoryCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long debug;
  char str[MAX_STRING_SIZE];
  long error;

  debug = atol( (char *)pcad->b );
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 * Set default value on CLEAR.
 * Do not clear the output fields since these values are pulled
 * into the database during command activity.
 */
      strcpy( (char *)pcad->a, "NONE");
      db_post_events( pcad, &pcad->a, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "Trajectory calculation field is blank" );
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "Trajectory calculation field too long" );
        ret = CAD_REJECT;
      }
      else if( !strcmp(str, "NONE") )
      {
        if( debug )
          errlogPrintf("simulateCAD - PRESET: Setting mode to NONE\n" );
        *(long *)pcad->vala = NO_ADJ;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "ADJUST_VEL") )
      {
        if( debug )
          errlogPrintf("simulateCAD - PRESET: Setting mode to ADJUST_VEL;\n" );
        *(long *)pcad->vala = VELOCITY;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "FULL") )
      {
        if( debug )
          errlogPrintf("simulateCAD - PRESET: Setting mode to FULL\n" );
        *(long *)pcad->vala = FULL;
        ret = CAD_ACCEPT;
      }
      else
      {
        sprintf( pcad->mess, "%s: Not a valid Trajectory calc. mode", str );
        ret = CAD_REJECT;
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
epicsRegisterFunction(trajectoryCAD);
