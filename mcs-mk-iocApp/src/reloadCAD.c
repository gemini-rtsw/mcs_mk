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
#include <mcssir.h>


/* 
 *  INPUTS:
 *      pcad->a = Choice of parameter file to download	(STRING).
 *                TELESCOPE
 *		  TAPEPOLYS
 *		  AXISLIMITS
 *		  SONY
 *		  LOGDATA
 *		  ALL_FILES
 *      pcad->b = Current debug level 0/1		(STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = FILE ID				(LONG).
 *
 */

long reloadCAD( struct cadRecord *pcad )
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
/*
 *  Set default value on CLEAR.
 */
      strcpy( (char *)pcad->a, "TELESCOPE");
      db_post_events( pcad, &pcad->a, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "Please specify a parameter file");
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "Parameter file name too long");
        ret = CAD_REJECT;
      }
      else if( !strcmp(str, "TELESCOPE") )
      {
        if( debug )
          errlogPrintf("reloadCAD - PRESET: Loading TELESCOPE file\n");
        *(long *)pcad->vala = MCS_TELESCOPE_PAR;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "TAPEPOLYS") )
      {
        if( debug )
          errlogPrintf("reloadCAD - PRESET: Loading TAPEPOLYS file\n");
        *(long *)pcad->vala = MCS_TAPEPOLYS_PAR;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "AXISLIMITS") )
      {
        if( debug )
          errlogPrintf("reloadCAD - PRESET: Loading AXISLIMITS file\n");
        *(long *)pcad->vala = MCS_AXISLIMITS_PAR;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "SONY") )
      {
        if( debug )
          printf("reloadCAD - PRESET: Loading SONY file\n");
        *(long *)pcad->vala = MCS_SONY_PAR;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "LOGDATA") )
      {
        if( debug )
          printf("reloadCAD - PRESET: Loading LOGDATA file\n");
        *(long *)pcad->vala = MCS_LOGDATA_PAR;
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "ALL_FILES") )
      {
        if( debug )
          printf("reloadCAD - PRESET: Loading ALL_FILES\n");
        *(long *)pcad->vala = MCS_ALLFILES_PAR;
        ret = CAD_ACCEPT;
      }
      else
      {
        sprintf( pcad->mess, "%s: Not a valid parameter file", str );
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
epicsRegisterFunction(reloadCAD);
