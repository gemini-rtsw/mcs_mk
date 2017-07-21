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
#include <cadRecord.h>
#include <cad.h>


/*
 *  INPUTS:
 *	pcad->a = Debug Level 0/1 (STRING).
 *
 *  OUTPUTS:
 *	None.
 */

long rebootCAD( struct cadRecord *pcad )
{
  long ret;
  long debug;

  debug = atol( (char *)pcad->a );
  if( debug )
    printf("Inside rebootCAD\n");
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      /* No arguments to check here */
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveSTART:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveSTOP:
      ret = CAD_ACCEPT;
      break;

    default:
      break;
  }
  return ret;
}
epicsRegisterFunction(rebootCAD);
