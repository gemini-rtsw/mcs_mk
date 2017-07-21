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
#include <mcssir.h>
#include <mcs.h>


/* 
 *  INPUTS:
 *	pcad->a = New Debug Level NONE/MIN/FULL  (STRING).
 *      pcad->b = Current Debug Level  0/1       (STRING).
 *
 *  OUTPUTS:
 *	pcad->vala = New Debug Level  0/1        (LONG).
 *
 */

long debugCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long debug;
  char str[MAX_STRING_SIZE];
  long error;

  debug = atol( (char *)pcad->b );
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:

/* Set default value on CLEAR */

      strcpy( (char *)pcad->a, "NONE" );
      db_post_events( pcad, &pcad->a, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "Debug mode field is blank" );
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "Debug mode field too long" );
        ret = CAD_REJECT;
      }
      else if( !strcmp(str, "NONE") )
      {
        if( debug )
          printf("debugCAD - PRESET: Setting mode to NONE\n");
        *(long *)pcad->vala = MCS_NONE;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "FULL") || !strcmp(str, "MIN") )
      {
        if( debug )
          printf("debugCAD - PRESET: Setting mode to %s\n", str);
        *(long *)pcad->vala = MCS_FULL;
        ret = CAD_ACCEPT;
      }
      else 
      {
        sprintf( pcad->mess, "%s: Not supported by the MCS", str );
        ret = CAD_REJECT;
      }
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
epicsRegisterFunction(debugCAD);
