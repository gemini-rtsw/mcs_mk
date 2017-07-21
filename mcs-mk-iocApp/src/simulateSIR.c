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
 *	psir->rval = Simulate Level (STRING). This will be 0/1/2/3.
 *
 *  OUTPUTS:
 *	psir->val  = Simulate Level (STRING) -  (for Engineering Screens).
 *			NONE
 *			VSM
 *			FAST
 *			FULL
 */

long simulateSIR( struct sirRecord *psir )
{
  long level;
  long ret;

  ret   = 0;
  level = atol( (char *)psir->rval );
  switch( level )
  {
    case MCS_NONE:
      strcpy( (char *)psir->val, "NONE" );
      break;

    case MCS_VSM:
      strcpy( (char *)psir->val, "VSM" );
      break;

    case MCS_FAST:
      strcpy( (char *)psir->val, "FAST" );
      break;

    case MCS_FULL:
      strcpy( (char *)psir->val, "FULL" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(simulateSIR);
