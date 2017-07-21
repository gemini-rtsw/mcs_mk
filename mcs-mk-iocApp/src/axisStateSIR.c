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
#include <sirRecord.h>
#include <mcssir.h>

/* 
 *  INPUTS:
 *	psir->rval = Axis State (STRING). This will be 0/1/2/3.
 *
 *  OUTPUTS:
 *	psir->val  = Axis State (STRING) -  (for Engineering Screens).
 *				BRAKED
 *				STATIONARY
 *				SLEWING
 *				TRACKING
 *                              APPLY BRAKES
 *                              RELEASE BRAKES
 *                              INTERLOCK
 */

long axisStateSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_BRAKED:
      strcpy( (char *)psir->val, "BRAKED" );
      break;
 
    case MCS_STATIONARY:
      strcpy( (char *)psir->val, "STATIONARY" );
      break;

    case MCS_SLEWING:
      strcpy( (char *)psir->val, "SLEWING" );
      break;

    case MCS_TRACKING:
      strcpy( (char *)psir->val, "TRACKING" );
      break;

    case MCS_APPLY_BRAKES:
      strcpy( (char *)psir->val, "APPLY BRAKES" );
      break;

    case MCS_RELEASE_BRAKES:
      strcpy( (char *)psir->val, "RELEASE BRAKES" );
      break;

    case MCS_INTERLOCK:
      strcpy( (char *)psir->val, "INTERLOCK" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(axisStateSIR);
