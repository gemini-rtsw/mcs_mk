/*
*   FILENAME
*   simRoutines.c 
*
*   FUNCTION NAME(S)
*   mcInitTrajMode    - set the trajectory calculation mode at initialisation time
*   mcGetTrajLevel    - fetch current trajectory calculation mode
*   mcTrajectoryMode  - manipulate trajectory calculation mode 
*
*/
/* *INDENT-OFF* */
/*
 *
 */
/* *INDENT-ON* */


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
#include <subRecord.h>
#include <genSubRecord.h>
#include <sirRecord.h>
#include <mcscad.h>
#include <mcs.h>
#include <drvPmac.h>

#include <cadRecord.h>
#include <cad.h>
#include <menuCarstates.h> 
#include <timeLib.h>

#include <tcsServo.h>

#define SIM_STOPPED 0
#define SIM_MOVING  1
#define SIM_FOLLOWING 2

static int intTrajectory = 0 ;        /* Internal mode */

int mcGetTrajLevel (void)
{

  return intTrajectory ;

}


/*+
 *   Function name:
 *   mcInitTrajMode
 *
 *   Purpose:
 *   Set the trajectory calculation mode at initialisation time
 *
 *   Description:
 *   EPICS records have a field SIMM that determines whether they operate
 *   in simulation mode or not. This routine sets this mode at initialisation
 *   time
 *
 *   Invocation:
 *   mcInitTrajMode(pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pgsub    (struct genSubRecord *)  Pointer to genSub structure
 *
 *   Epics inputs:
 *   a => demand trajectory calculation mode
 *
 *   Epics outputs:
 *   vala => trajectory calculation mode
 *   valb => current trajectory calculation mode
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long mcInitTrajMode (struct genSubRecord *pgsub) 
{

  long demandTrajLevel ;

  demandTrajLevel = *(long *)pgsub->a ;

  if (mcGetTrajLevel()) {

/* Force the simulation mode to YES and check that the level is valid. If
*  it isn't then set it to FULL
*/

    *(long *)pgsub->valb = 1 ;
    if (demandTrajLevel < NO_ADJ || demandTrajLevel > FULL)
      demandTrajLevel = NO_ADJ ;
    *(long *)pgsub->vala = demandTrajLevel ;
  } else {

/* If not simulating then set the mode to No and force the level to be
*  NONE irrespective of what the demand level is
*/
    *(long *)pgsub->valb = 0 ;
    *(long *)pgsub->vala = NO_ADJ;
  } 

  return 0 ;
}


/*+
 *   Function name:
 *   mcTrajectoryMode
 *
 *   Purpose:
 *   Update the Trajectory level of the Mount software
 *
 *   Desmciption:
 *   This routine is used in conjunction with the mcInitSimMode routine
 *   to update the Trajectory level of the Mount software. Note it
 *   only adjusts the Trajectory level not the simulation mode. The
 *   Trajectory mode is set at boot time and can't be changed without
 *   stopping and restarting the software.
 *
 *   Invocation:
 *   mcTrajectoryMode(pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pgsub    (struct genSubRecord *)  Pointer to genSub structure
 *
 *
 *   Epics inputs:
 *   a => demand Trajectory level
 *
 *   Epics outputs:
 *   vala => output Trajectory level
 *   valb => current Trajectory mode
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long mcTrajectoryMode (struct genSubRecord *pgsub) 
{

  long demandMode ;

  demandMode = *(long *)pgsub->a ;
 
  printf("demandMode = %ld\n",demandMode);
    if (demandMode < NO_ADJ || demandMode > FULL)
      demandMode = NO_ADJ ; 

    *(long *)pgsub->vala = (long) demandMode ;


  return 0 ;
}
epicsRegisterFunction(mcTrajectoryMode);
epicsRegisterFunction(mcInitTrajMode);

