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
 *	psir->rval = Following State (STRING). This will be 0/1.
 *
 *  OUTPUTS:
 *	psir->val  = Following State (STRING) -  (for Engineering Screens).
 *				OFF
 *				ON
 */

long followSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_IGNORING:
      strcpy( (char *)psir->val, "OFF" );
      break;

    case MCS_FOLLOWING:
      strcpy( (char *)psir->val, "ON" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
  }
  return ret;
}
epicsRegisterFunction(followSIR);
