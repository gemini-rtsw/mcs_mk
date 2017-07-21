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
 *	psir->rval = State of PMAC Fast Data Logging (STRING). This will be 0/1/2.
 *
 *  OUTPUTS:
 *	psir->val  = State of PMAC Fast Data Logging (STRING)-(for Engineering Screens).
 *			OFF
 *			PRIMED
 *                      ON
 */

long logDataSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_LOG_OFF:
      strcpy( (char *)psir->val, "OFF" );
      break;

    case MCS_LOG_PRIMED:
      strcpy( (char *)psir->val, "PRIMED" );
      break;

    case MCS_LOG_ON:
      strcpy( (char *)psir->val, "ON" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(logDataSIR);
