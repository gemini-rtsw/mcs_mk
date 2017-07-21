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
 *	psir->rval = State of MCS (STRING). This will be 0/1/2.
 *
 *  OUTPUTS:
 *	psir->val  = State of MCS (STRING) -  (for Engineering Screens).
 *			BOOTING
 *			INITIALISING
 *                      RUNNING
 */

long stateSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_BOOTING:
      strcpy( (char *)psir->val, "BOOTING" );
      break;

    case MCS_INITIALISING:
      strcpy( (char *)psir->val, "INITIALISING" );
      break;

    case MCS_RUNNING:
      strcpy( (char *)psir->val, "RUNNING" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(stateSIR);
