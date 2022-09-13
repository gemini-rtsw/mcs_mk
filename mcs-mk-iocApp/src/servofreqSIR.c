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
#include <drvPmac.h>


/* 
 *  This routine interrogates PMAC to find out what the Servo
 *  frequency is. This routine is run once at iocInit from 3 SIR
 *  records.
 *
 *  INPUTS:
 *	psir->val = Card Number        (DOUBLE).
 *
 *  OUTPUTS:
 *	psir->val = Servo Frequency    (DOUBLE).
 */

long servofreqSIR( struct sirRecord *psir )
{
  long I10;
  long card;
  /* Removed during EPICS 7 Migration
  long terminator;
  */
  char command[MAX_STRING_SIZE];
  char response[MAX_STRING_SIZE];
  char errmsg[MAX_STRING_SIZE];

  card = (long)(*(double *)psir->val);

  sprintf(command, "I10");
  /* Removed during EPICS 7 Migration
  terminator = drvPmacMbxWriteRead(card, command, response, errmsg);
  */
  drvPmacMbxWriteRead(card, command, response, errmsg);
  sscanf(response, "%ld", &I10);
  *(double *)psir->val = (PMAC_INTERRUPT_FACTOR/(double)I10) * 1000.0;
  
  return(0);
}
epicsRegisterFunction(servofreqSIR);

