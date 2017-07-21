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
 *	psir->rval = Current VE algorithm (STRING). This will be 0/1/2/3/4.
 *
 *  OUTPUTS:
 *	psir->val  = Current VE algorithm (STRING) -  (for Engineering Screens).
 *				FDE
 *				N
 *				M&N
 *				ALL_HEADS
 *				EL_N
 */

long axisVEalgoSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_FDE:
      strcpy( (char *)psir->val, "FDE" );
      break;

    case MCS_N:
      strcpy( (char *)psir->val, "TAPE HEAD N" );
      break;
 
    case MCS_M_N:
      strcpy( (char *)psir->val, "TAPE HEADS M&N" );
      break;

    case MCS_ALL_HEADS:
      strcpy( (char *)psir->val, "ALL_HEADS" );
      break;

    case MCS_EL_N:
      strcpy( (char *)psir->val, "TAPE HEAD N + T" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(axisVEalgoSIR);
