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
 *	psir->rval = In-Position state (STRING). This will be 0/1.
 *
 *  OUTPUTS:
 *	psir->val  = In-Position state (STRING) - (for Engineering Screens).
 *			FALSE
 *			TRUE
 */

long inPositionSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_FALSE:
      strcpy( (char *)psir->val, "FALSE" );
      break;

    case MCS_TRUE:
      strcpy( (char *)psir->val, "TRUE" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(inPositionSIR);
