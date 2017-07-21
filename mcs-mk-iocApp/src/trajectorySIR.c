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
 *	psir->rval = trajectory option (STRING). This will be 0/1/2.
 *
 *  OUTPUTS:
 *	psir->val  = trajectory option (STRING) -  (for Engineering Screens).
 *				NO_ADJUSTMENT
 *                              ADJUST_VEL 
 *		                ADJUST_ACCEL
 */

long trajectorySIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  
  switch( state )
  {
    case NO_ADJUST:
      strcpy( (char *)psir->val, "NONE" );
      break;

    case ADJUST_VEL:
      strcpy( (char *)psir->val, "VELOCITY" );
      break;

    case ADJUST_ACCEL:
      strcpy( (char *)psir->val, "FULL" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
  }
  return ret;
}
epicsRegisterFunction(trajectorySIR);
