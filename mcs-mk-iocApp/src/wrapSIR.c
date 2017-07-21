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
 *	psir->rval = Azimuth wrap (STRING). This will be 0/1/2.
 *
 *  OUTPUTS:
 *	psir->val  = Azimuth wrap (STRING) -  (for Engineering Screens).
 *			WRAP A
 *			WRAP B
 *                      WRAP C
 *                      UNKNOWN
 */

long wrapSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_WRAP_A:
      strcpy( (char *)psir->val, "WRAP A" );
      break;

    case MCS_WRAP_B:
      strcpy( (char *)psir->val, "WRAP B" );
      break;

    case MCS_WRAP_C:
      strcpy( (char *)psir->val, "WRAP C" );
      break;

    default:
      strcpy( (char *)psir->val, "UNKNOWN" );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(wrapSIR);
