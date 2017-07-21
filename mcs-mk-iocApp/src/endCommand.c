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
#include <genSubRecord.h>
#include <menuCarstates.h>
#include <mcssir.h>


/*
 * Output:	pgsub->vala = Mask Out	(LONG)
 *
 *  0 = Do nothing
 *  1 = Set Car Idle
 *  2 = Set Car Error
 *
 */

long endCommand( struct genSubRecord *pgsub )
{
  long command;
  long carState;
  long axisState;
  long prevAS;
  long maskInAz;
  long maskInEl;
  long maskIn;
  long maskOut;
  long card;
  long debug;

  command   = *(long *)pgsub->a;
  carState  = *(long *)pgsub->b;
  axisState = *(long *)pgsub->c;
  prevAS    = *(long *)pgsub->d;
  maskInAz  = *(long *)pgsub->e;
  maskInEl  = *(long *)pgsub->f;
  card      = (long)(*(double *)pgsub->g);
  debug     = *(long *)pgsub->h;

  if( card == 0 )
    maskIn = maskInAz;
  else 
    maskIn = maskInEl;

  *(long *)pgsub->d = axisState;

  if( debug )
    printf("endCommand: command = %ld, carState = %ld, axisState = %ld, prevAS = %ld\n",
            command, carState, axisState, prevAS);

  maskOut = 0;
  if( command == MCS_MOVE )
  {
    if( (prevAS == MCS_SLEWING) && (axisState == MCS_STATIONARY) )
      maskOut |= 1;				/* Set Idle  */
    else if( axisState == MCS_INTERLOCK )
      maskOut |= 2;				/* Set Error */
  }
  else if( command == MCS_STOP )
  {
    if( (axisState == MCS_BRAKED) && (maskIn == 5) )
      maskOut |= 1;				/* Set Idle */
    else if( (axisState == MCS_STATIONARY) && (maskIn == 3) )
      maskOut |= 1;				/* Set Idle */
    else if( axisState == MCS_INTERLOCK )
      maskOut |= 2;				/* Set Error */
  }
  else if( command == MCS_PARK )
  {
    if( (prevAS == MCS_SLEWING) && (axisState == MCS_STATIONARY) )
      maskOut |= 1;				/* Apply Brakes */
    else if( axisState == MCS_INTERLOCK )
      maskOut |= 2;				/* Set Error    */
  }

  *(long *)pgsub->vala = maskOut;

  return(0);
}
epicsRegisterFunction(endCommand);
