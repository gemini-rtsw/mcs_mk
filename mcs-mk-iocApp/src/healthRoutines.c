/*
*   FILENAME
*   healthRoutines.c
*
*   FUNCTION NAME(S)
*   mcHealthCombine - combine health values to form overall health of MRCS
*   mcMotorHealth   - generate a health value for the wrap or axis (Az/El)
*   mcTstampHealth  - generate health of time stamping system
*
*/
/* *INDENT-OFF* */
/*
 * $Log: healthRoutines.c,v $
 * Revision 1.4  2008/08/25 19:49:34  gemvx
 *
 * 	capfast/motionProg.sch:Set P102=0 when not follow, P102=1 when follow.
 *  	capfast/pmacCommands.sch capfast/pmacInit1.sch
 *  	capfast/trackingOff.sch src/cad/followCAD.c src/cad/moveCAD.c
 *  	src/par/tapePolysCP.par
 * 	src/par/telescopeCP.par: P102 varuiable splitted into P102_ON
 * 	and P102_OFF
 *
 * Revision 1.2  2001/10/22 17:54:48  gemvx
 * *** empty log message ***
 *
 * Revision 1.1  2001/08/20 16:54:54  gemvx
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
 * Revision 1.0  2000/01/27 00:56:34  cjm
 * Add routine mcHealthCombine and a standard header
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

/*+
 *   Function name:
 *   mcHealthCombine
 *
 *   Purpose:
 *   Combine all health values into a single overall health
 *
 *   Description:
 *   The individual health values are read from the input links. If any
 *   of them are bad then the overall health is bad. If none are bad but
 *   some are warning then the overall health is warning otherwise the
 *   health is good. The combined health is represented by an integer
 *   and a string. If there are multiple inputs that are set to WARNING or
 *   BAD then the health message is taken from the first BAD or WARNING input.
 *
 *   Invocation:
 *   mcHealthCombine(pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pgsub    (struct genSubRecord *) Pointer to gensub structure
 *
 *   Epics inputs:
 *
 *   a => First health string, GOOD, WARNING or BAD
 *   b => Second health string, GOOD WARNING or BAD
 *   c => Third health string, GOOD WARNING or BAD
 *   d => Fourth health string, GOOD WARNING or BAD
 *   e => Health message if any associated with a
 *   f => Health message if any associated with b
 *   g => Health message if any associated with c
 *   h => Health message if any associated with d
 *
 *   Epics outputs:
 *   vala => Health message
 *   valb => Combined health as a string
 *   valc => Combined health encoded as an integer 
 *
 *   Function value:
 *   Return value from function e.g.
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *   Deficiencies:
 *   The routine currently generates an overall health of 0, 1 or 2 to match
 *   be 0, 100, 200
 *
 *-
 */

long mcHealthCombine (struct genSubRecord *pgsub) 
{
  long outHealth ;                  /* Output health value */
  char health[16];                  /* Output health as a string */
  char healthMess[MAX_STRING_SIZE]; /* Output health message (if any) */

/* Initialise health to bad */
  outHealth = MCS_BAD ;
  strcpy (health, "BAD") ;
  strcpy (healthMess, " ") ;

/* Check inputs and compute output */
  if (!strncmp((char *)pgsub->a, "GOOD",4) &&
      !strncmp((char *)pgsub->b, "GOOD",4) &&
      !strncmp((char *)pgsub->c, "GOOD",4) &&
      !strncmp((char *)pgsub->d, "GOOD",4)) {
    outHealth = MCS_GOOD ;
    strcpy (health, "GOOD");
  } else {
   if (!strncmp((char *)pgsub->a, "WARNING",7) ||
       !strncmp((char *)pgsub->b, "WARNING",7) ||
       !strncmp((char *)pgsub->c, "WARNING",7) ||
       !strncmp((char *)pgsub->d, "WARNING",7)) {
     if (!strncmp((char *)pgsub->a, "WARNING",7)) {
       strcpy(healthMess, pgsub->e) ;
     } else if (!strncmp((char *)pgsub->b, "WARNING",7)) {
       strcpy(healthMess, pgsub->f) ;
     } else if (!strncmp((char *)pgsub->c, "WARNING",7)) {
       strcpy(healthMess, pgsub->g) ;
     } else if (!strncmp((char *)pgsub->d, "WARNING",7)) {
       strcpy(healthMess, pgsub->h) ;
     }
     outHealth = MCS_WARNING ;
     strcpy (health, "WARNING") ;
   }
   if (!strncmp((char *)pgsub->a, "BAD",3) ||
       !strncmp((char *)pgsub->b, "BAD",3) ||
       !strncmp((char *)pgsub->c, "BAD",3) ||
       !strncmp((char *)pgsub->d, "BAD",3)) {
     if (!strncmp((char *)pgsub->a, "BAD",3)) {
       strcpy(healthMess, pgsub->e) ;
     } else if (!strncmp((char *)pgsub->b, "BAD",3)) {
       strcpy(healthMess, pgsub->f) ;
     } else if (!strncmp((char *)pgsub->c, "BAD",3)) {
       strcpy(healthMess, pgsub->g) ;
     } else if (!strncmp((char *)pgsub->d, "BAD",3)) {
       strcpy(healthMess, pgsub->h) ;
     }
     outHealth = MCS_BAD ;
     strcpy (health, "BAD") ;
   }
  }

  strcpy (pgsub->vala, healthMess) ;
  strcpy (pgsub->valb, health) ;
  *(long *)pgsub->valc = outHealth ;

  return 0 ;

}


/*+
 *   Function name:
 *   mcMotorHealth
 *
 *   Purpose:
 *   Generate an overall health value from the PMAC status bits
 *
 *   Description:
 *   Each PMAC driven motor has a status word associated with it. The
 *   relevant bits of this word are read by this routine and a health
 *   value generated for that mechanism. The first error bit that is
 *   encountered is used to generate a string to accompany the health
 *   status. 
 *
 *   Invocation:
 *   mcMotorHealth(pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pgsub    (struct genSubRecord *) Pointer to gensub structure
 *
 *   Epics inputs:
 *
 *   a => Fatal following error
 *   b => Amplifier fault error
 *   c => Positive end limit set
 *   d => Negative end limit set
 *   e => Data block error
 *   f => Warning following error
 *   j => GIS Drive Condition
 *
 *   Epics outputs:
 *   vala => health message 
 *   valb => health value GOOD, WARNING or BAD
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 *
 *   Deficiencies:
 *   At the moment the amplifier fault state is ignored as there needs to be
 *   a way of distinguishing between a real fault and the amplifier simply
 *   not being switched on. If the amplifier state is included we always
 *   end up with an error when the system is not being used.
 *-
 */

long mcMotorHealth (struct genSubRecord *pgsub) 
{

  char health[16] ;             /* Motor health value */
  char mesg[MAX_STRING_SIZE] ;  /* Output health message */
  /* Removed during EPICS 7 Migration
  long gisState ;*/               /* State of GIS */

/* Initialise health output to GOOD */
  strcpy (mesg, " ") ;
  strcpy (health, "GOOD") ;

  /* Removed during EPICS 7 Migration
  gisState = *(long *)pgsub->j ;
  */

/* Check inputs and compute output */
  if (*(long *)pgsub->a) {
    strncpy(mesg,"Fatal following error", MAX_STRING_SIZE);
    strcpy(health, "BAD") ;
/******************************************
  } else if (*(long *)pgsub->b) {
    strncpy(mesg, "Amplifier fault error", MAX_STRING_SIZE);
    strcpy(health, "BAD") ;
*/
  } else if (*(long *)pgsub->c) {
    strncpy (mesg, "Positive end limit set", MAX_STRING_SIZE) ;
    strcpy (health, "BAD") ;
  } else if (*(long *)pgsub->d) {
    strncpy (mesg, "Negative end limit set", MAX_STRING_SIZE) ;
    strcpy (health, "BAD") ;
  } else if (*(long *)pgsub->e) {
    strncpy (mesg, "Data block error", MAX_STRING_SIZE) ;
    strcpy (health, "BAD") ;
  } else if (*(long *)pgsub->f) {
    strncpy (mesg, "Warning following error", MAX_STRING_SIZE) ;
    strcpy (health, "WARNING") ;
  }

  strncpy (pgsub->vala, mesg, MAX_STRING_SIZE) ;
  strncpy (pgsub->valb, health, MAX_STRING_SIZE) ;

  return 0 ;

}


/*+
 *   Function name:
 *   mcTstampHealth
 *
 *   Purpose:
 *   Generate an overall health for the time stamping system
 *
 *   Description:
 *   The health of the time stamping system is determined by whether
 *   the time stamping system is running and if it is by whether the
 *   time being measured is sufficiently close to the Bancomm time.
 *   The routine generates a health message and value that is later
 *   combined with other health values to generate an overall health for 
 *   the whole Cass. Rotator.
 *
 *   Invocation:
 *   mcTstampHealth(pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pgsub    (struct genSubRecord *) Pointer to gensub structure
 *
 *   Epics inputs:
 *
 *   a => Health of time stamp program
 *   b => Health of time stamp
 *   c => Time stamp health message
 *
 *   Epics outputs:
 *   vala => Health of time stamp system GOOD, WARNING or BAD
 *   valb => Health message
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long mcTstampHealth (struct genSubRecord *pgsub) 
{
  char health[16];                  /* Output health as a string */
  char healthMess[MAX_STRING_SIZE]; /* Output health message (if any) */

/* Initialise health to good */
  strcpy (health, "GOOD") ;
  strcpy (healthMess, " ") ;

/* Check inputs and compute output */
  if (!strncmp((char *)pgsub->a, "GOOD",4) &&
      !strncmp((char *)pgsub->b, "GOOD",4)) {
    strcpy (health, "GOOD");
  }

   if (!strncmp((char *)pgsub->a, "WARNING",7) ||
       !strncmp((char *)pgsub->b, "WARNING",7)) {
     if (!strncmp((char *)pgsub->a, "WARNING",7)) {
       strcpy(healthMess, "Time stamping not running") ;
     } else if (!strncmp((char *)pgsub->b, "WARNING",7)) {
       strcpy(healthMess, (char *)pgsub->c) ;
     }
     strcpy (health, "WARNING") ;
   } 

   if (!strncmp((char *)pgsub->a, "BAD",3) ||
       !strncmp((char *)pgsub->b, "BAD",3)) {
     if (!strncmp((char *)pgsub->a, "BAD",3)) {
       strcpy(healthMess, "Time stamping not running") ;
     } else if (!strncmp((char *)pgsub->b, "BAD",3)) { 
       strcpy(healthMess, (char *)pgsub->c) ;
     }
     strcpy (health, "BAD") ;
   }

  strcpy (pgsub->vala, health) ;
  strcpy (pgsub->valb, healthMess) ;

  return 0 ;

}
epicsRegisterFunction(mcMotorHealth);
epicsRegisterFunction(mcTstampHealth);
epicsRegisterFunction(mcHealthCombine);

