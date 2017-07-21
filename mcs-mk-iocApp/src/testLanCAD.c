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
#include <mcs.h>


/* 
 *  INPUTS:
 *      pcad->a = File Name     STRING->STRING.
 *
 *  OUTPUTS:
 *      pcad->vala = File Name  (STRING).
 */

/*#define DEFAULT_FILE_NAME "lanTest.dat"*/
#define DEFAULT_FILE_NAME "/gem_sw/work/data/mcs/lanTest.dat"


long testLanCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long error;
  char str[MAX_STRING_SIZE];

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 0 );
      if( error == ALL_BLANKS )
      {
        strcpy( (char *)pcad->a, DEFAULT_FILE_NAME);
        db_post_events( pcad, pcad->a, 1 );
        strcpy( pcad->vala, pcad->a );
        ret = CAD_ACCEPT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "Filename too long" );
        ret = CAD_REJECT;
      }
      else
      {
        strcpy( pcad->vala, str );
        ret = CAD_ACCEPT;
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
epicsRegisterFunction(testLanCAD);
