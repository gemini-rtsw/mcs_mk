/*
*   FILENAME
*   mcHealthSIR.c
*
*   FUNCTION NAME(S)
*   mcDataHealth - set health for TCS data stream
*   mcHealthSIR - set alarm status of health record
*
*/
/* *INDENT-OFF* */
/*
 * $Log: mcHealthSIR.c,v $
 * Revision 1.2  2001/10/22 17:54:52  gemvx
 * *** empty log message ***
 *
 * Revision 1.1  2001/08/20 16:54:55  gemvx
 *
 * In this version only the "Double Buffer" option is allowed, in
 * order to avoid misunderstanding in the installation.
 * Modified Files:
 *  	src/misc/miscRoutines.c src/par/telescope.par
 *  	src/par/telescopeCP.par src/par/telescopeMK.par
 *  	src/sir/Makefile.Vx startup/.cvsignore startup/mv167st.vws
 *  	startup/mvstage.vws startup/startupCP.vws
 *
 * Added files are related to PMAC simulator.
 *
 * Besides that some modifications in the health tree were made.
 *
 *  	capfast/mcMiscHealth.sym capfast/pmacSimulator.sch
 *  	capfast/pmacSimulator.sym dl/Diag_dram.adl dl/mcHealthTree.adl
 *  	dl/mcMiscHealth.adl dl/mcMotorHealth.adl dl/mcTimeHealth.adl
 *  	dl/tstamp.adl src/misc/healthRoutines.c src/misc/simRoutines.c
 *  	src/misc/tcsRandom.c src/misc/tcsRandom.h src/misc/tcsServo.c
 *  	src/misc/tcsServo.h src/sir/mcHealthSIR.c
 *
 * Revision 1.3  2000/06/06 20:16:58  cjm
 * Add routine to compute a health value based on arrayS
 *
 * Revision 1.2  2000/03/21 19:41:45  cjm
 * Replace mccssir.h with crcs.h
 *
 * Revision 1.1  2000/03/20 22:04:51  cjm
 * Replacement for healthSIR.c with extra routine for setting alarm state
 *
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
#include <alarm.h>
#include <sirRecord.h>
#include <mcs.h>

/*+
 *   Function name:
 *   mcDataHealth
 *
 *   Purpose:
 *   Sets the health of the TCS data stream 
 *
 *   Desmciption:
 *   The status of the continuous stream of data from the TCS is encoded
 *   into the arrayS record. This routine takes the value from that record
 *   and generates a health value and message that can be combined into
 *   the overall health tree.
 *
 *   Invocation:
 *   mcDataHealth (psir)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    psir     (struct sirRecord *)  Pointer to SIR record structure
 *
 *   Epics inputs:
 *     rval => Raw input value 0, 1 or 2
 *
 *   Epics outputs:
 *     imss => An input message that will be copied to the output
 *     val  => The health GOOD, WARNING or BAD
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long mcDataHealth( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case 0:
      strcpy( (char *)psir->val, "GOOD" );
      strcpy( psir->imss, " ") ;
      break;

    case 1:
      strcpy( (char *)psir->val, "BAD" );
      strcpy( psir->imss, "Data out of range") ;
      break;

    case 2:
      strcpy( (char *)psir->val, "BAD" );
      strcpy( psir->imss, "Data too early or late") ;
      break;

    default:
      strcpy( (char *)psir->val, "BAD" );
      strcpy( psir->imss, "Unspecified data error") ;
      break;
  }
  return ret;
}

/*+
 *   Function name:
 *   mcHealthSIR
 *
 *   Purpose:
 *   Sets the alarm state of the health record
 *
 *   Desmciption:
 *   On the basis of the input value, set the alarm state of the record
 *
 *   Invocation:
 *   mcHealthSIR (psir)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    psir     (struct sirRecord *)  Pointer to SIR record structure
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long mcHealthSIR (struct sirRecord *psir)
{
  int alarm = INVALID_ALARM ;

/* Check the input value and set the alarm state accordingly */

  if (!strncmp (psir->val, "GOOD", 4)) {
    alarm = NO_ALARM ;
  } else if (!strncmp (psir->val, "WARNING", 7)) {
    alarm = MINOR_ALARM ;
  } else if (!strncmp (psir->val, "BAD", 3)) {
    alarm = MAJOR_ALARM ;
  }

  psir->brsv = alarm ;
  

  return alarm ;

}
epicsRegisterFunction(mcHealthSIR);
epicsRegisterFunction(mcDataHealth);
