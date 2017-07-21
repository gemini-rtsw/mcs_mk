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
#include <menuCarstates.h>
#include <mcssir.h>
#include <mcs.h>


/* 
 *  INPUTS:
 *      pcad->a = Axis to be logged                     STRING -> LONG
 *      pcad->b = Current Debug Level 0/1               STRING -> LONG
 *
 *  OUTPUTS:
 *      pcad->vala = Axis to be logged                  (LONG)
 */

long logTrackingCAD( struct cadRecord *pcad )
{
  long   debug;
  long   axis;
  long   error;
  long   ret = 0;

  /* These are read from database links */
  axis         = atol( (char *)pcad->a );
  debug        = atol( (char *)pcad->b );

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      ret = CAD_ACCEPT;
      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->a );
        if( debug && error )
          printf("logTrackingCAD: error = %ld from check_numeric for logging axis\n", error);
        if( error )
        {
            sprintf(pcad->mess, "Axis to be logged not selected");
            ret = CAD_REJECT;
        }

        if( ret == CAD_ACCEPT )
        {
          /* If we get here, we've passed all the tests to accept the logTracking command */

          *(long *)pcad->vala   = axis;
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
epicsRegisterFunction(logTrackingCAD);
