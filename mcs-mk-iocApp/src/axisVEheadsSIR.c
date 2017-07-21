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
 *	psir->rval = Tape heads to use in VE algorithm (STRING). 
 *                   This will be 0-11.
 *
 *  OUTPUTS:
 *	psir->val  = Tape heads to use in VE algorithm (STRING).
 *                   For Engineering Screens.
 *				NONE
 *				HEAD 1
 *				HEAD 2
 *				HEAD 3
 *				HEAD 4
 *				HEADS 1,3
 *				HEADS 2,4
 *				HEADS 1,2
 *				HEADS 3,4
 *				HEAD 1+T
 *				HEAD 2+T
 *                              HEADS 1,2,3,4
 *				HEADS 1+T, 2+T
 */

long axisVEheadsSIR( struct sirRecord *psir )
{
  long state;
  long ret;

  ret   = 0;
  state = atol( (char *)psir->rval );
  switch( state )
  {
    case MCS_NONE:
      strcpy( (char *)psir->val, "NONE" );
      break;

    case MCS_HEAD_1:
      strcpy( (char *)psir->val, "HEAD 1" );
      break;

    case MCS_HEAD_2:
      strcpy( (char *)psir->val, "HEAD 2" );
      break;
 
    case MCS_HEAD_3:
      strcpy( (char *)psir->val, "HEAD 3" );
      break;

    case MCS_HEAD_4:
      strcpy( (char *)psir->val, "HEAD 4" );
      break;

    case MCS_HEADS_1_3:
      strcpy( (char *)psir->val, "HEADS 1,3" );
      break;

    case MCS_HEADS_2_4:
      strcpy( (char *)psir->val, "HEADS 2,4" );
      break;

    case MCS_HEADS_1_2:
      strcpy( (char *)psir->val, "HEADS 1,2" );
      break;

    case MCS_HEADS_3_4:
      strcpy( (char *)psir->val, "HEADS 3,4" );
      break;

    case MCS_HEAD_1_T:
      strcpy( (char *)psir->val, "HEAD 1+T" );
      break;

    case MCS_HEAD_2_T:
      strcpy( (char *)psir->val, "HEAD 2+T" );
      break;

    case MCS_ALL_AZHEADS:
      strcpy( (char *)psir->val, "HEADS 1,2,3,4" );
      break;

    case MCS_ALL_ELHEADS:
      strcpy( (char *)psir->val, "HEADS 1+T, 2+T" );
      break;

    default:
      strcpy( (char *)psir->val, "  " );
      ret = -1;
      break;
  }
  return ret;
}
epicsRegisterFunction(axisVEheadsSIR);
