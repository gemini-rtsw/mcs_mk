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
 *      pcad->a = Current Debug Level      0/1             STRING -> LONG
 *      pcad->b = Azimuth Datum            0/1             STRING -> LONG
 *      pcad->c = Elevation Datum          0/1             STRING -> LONG
 *      pcad->d = State of Azimuth axis    0/1/2/3         STRING -> LONG
 *      pcad->e = State of Elevation axis  0/1/2/3         STRING -> LONG
 *
 *  OUTPUTS:
 */

long followCAD( struct cadRecord *pcad )
{
  long ret = 0;
  /* removed during Epics 7 migration
  long debug; 
  */
  long azDatum;
  long elDatum;
  /* removed during Epics 7 migration
  long azState;
  long elState; 
  */

  /* removed during Epics 7 migration
  debug   = atol( (char *)pcad->a ); 
  */
  azDatum = atol( (char *)pcad->b );
  elDatum = atol( (char *)pcad->c );
  /* removed during Epics 7 migration
  azState = atol( (char *)pcad->d );
  elState = atol( (char *)pcad->e );
  */
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      if( azDatum == MCS_NOT_DATUMED )
      {
        sprintf( pcad->mess, "The azimuth axis has not been datumed" );
        ret = CAD_REJECT;
      }
      else
      {
        if( elDatum == MCS_NOT_DATUMED )
        {
          sprintf( pcad->mess, "The Elevation axis has not been datumed" );
          ret = CAD_REJECT;
        }
        else
	{
	  printf("Follow CAD activated: PRESET\n");
          ret = CAD_ACCEPT;
        }
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
epicsRegisterFunction(followCAD);
