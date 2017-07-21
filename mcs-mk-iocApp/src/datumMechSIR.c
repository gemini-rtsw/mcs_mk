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
 *	psir->rval = Datum Mechanism (STRING). This will be 0/1/2/3/4.
 *
 *  OUTPUTS:
 *	psir->val  = Datum state (STRING) -  (for Engineering Screens).
 *				SONY SWITCH
 *				TAPE HEAD 1
 *				TAPE HEAD 2
 *				TAPE HEAD 3
 *				TAPE HEAD 4
 */

long datumMechSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_SWITCH:
      strcpy( (char *)psir->val, "SONY SWITCH" );
      break;

    case MCS_HEAD_1:
      strcpy( (char *)psir->val, "TAPE HEAD 1" );
      break;

    case MCS_HEAD_2:
      strcpy( (char *)psir->val, "TAPE HEAD 2" );
      break;

    case MCS_HEAD_3:
      strcpy( (char *)psir->val, "TAPE HEAD 3" );
      break;

    case MCS_HEAD_4:
      strcpy( (char *)psir->val, "TAPE HEAD 4" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
  }
  return ret;
}
epicsRegisterFunction(datumMechSIR);
