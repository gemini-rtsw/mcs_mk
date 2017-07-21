#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsPrint.h>
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
 *	psir->rval = State of 20Hz data (STRING). This will be 0/1/2.
 *
 *  OUTPUTS:
 *	psir->val  = State of 20Hz data (STRING) -  (for Engineering Screens).
 *			VALID
 *			INVALID
 *                      TIMEOUT
 */

long arraySIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_VALID:
      strcpy( (char *)psir->val, "VALID" );
      break;

    case MCS_INVALID:
      strcpy( (char *)psir->val, "INVALID" );
      break;

    case MCS_TIMEOUT:
      strcpy( (char *)psir->val, "TIMEOUT" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(arraySIR);
