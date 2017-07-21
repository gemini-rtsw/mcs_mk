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
 *	psir->rval = Datum state (STRING). This will be 0/1.
 *
 *  OUTPUTS:
 *	psir->val  = Datum state (STRING) -  (for Engineering Screens).
 *				NOT DATUMED
 *				DATUMED
 */

long datumSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_NOT_DATUMED:
      strcpy( (char *)psir->val, "NOT DATUMED" );
      break;

    case MCS_DATUMED:
      strcpy( (char *)psir->val, "DATUMED" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
  }
  return ret;
}
epicsRegisterFunction(datumSIR);
