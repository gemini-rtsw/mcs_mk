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
 *	psir->rval = Command Number (STRING). This will be 0 - 16.
 *
 *  OUTPUTS:
 *	psir->val  = Command Name (STRING) -  (for Engineering Screens).
 *
 */

long commandSIR( struct sirRecord *psir )
{
  long num;
  long ret;

  ret = 0;
  num = atol( (char *)psir->rval );
  switch( num )
  {
    case MCS_NOCOMMAND:
      strcpy( (char *)psir->val, " " );
      break;

    case MCS_REBOOT:
      strcpy( (char *)psir->val, "REBOOT" );
      break;

    case MCS_INIT:
      strcpy( (char *)psir->val, "INIT" );
      break;

    case MCS_DATUM:
      strcpy( (char *)psir->val, "DATUM" );
      break;

    case MCS_TEST:
      strcpy( (char *)psir->val, "TEST" );
      break;

    case MCS_DEBUG:
      strcpy( (char *)psir->val, "DEBUG" );
      break;

    case MCS_SIMULATE:
      strcpy( (char *)psir->val, "SIMULATE" );
      break;

    case MCS_STOP:
      strcpy( (char *)psir->val, "STOP" );
      break;

    case MCS_MOVE:
      strcpy( (char *)psir->val, "MOVE" );
      break;

    case MCS_FOLLOW:
      strcpy( (char *)psir->val, "FOLLOW" );
      break;

    case MCS_PARK:
      strcpy( (char *)psir->val, "PARK" );
      break;

    case MCS_AZCONFIG:
      strcpy( (char *)psir->val, "AZCONFIG" );
      break;

    case MCS_ELCONFIG:
      strcpy( (char *)psir->val, "ELCONFIG" );
      break;

    case MCS_LOGDATA:
      strcpy( (char *)psir->val, "LOGDATA" );
      break;

    case MCS_TOLERANCE:
      strcpy( (char *)psir->val, "TOLERANCE" );
      break;

    case MCS_CWMOVE:
      strcpy( (char *)psir->val, "CWMOVE" );
      break;

    case MCS_TESTLAN:
      strcpy( (char *)psir->val, "TESTLAN" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(commandSIR);
