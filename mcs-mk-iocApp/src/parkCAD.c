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
#include <mcscad.h>
#include <mcs.h>


/* 
 *  INPUTS:
 *      pcad->a = Requested azimuth park position		STRING -> DOUBLE
 *      pcad->b = Requested elevation park position		STRING -> DOUBLE
 *      pcad->c = Current Debug Level			0/1	STRING -> LONG
 *      pcad->d = Azimuth Datum				0/1	STRING -> LONG
 *      pcad->e = Elevation Datum			0/1	STRING -> LONG
 *      pcad->f = Azimuth Upper Limit				STRING -> DOUBLE
 *      pcad->g = Azimuth Lower Limit				STRING -> DOUBLE
 *      pcad->h = Elevation Upper Limit				STRING -> DOUBLE
 *      pcad->i = Elevation Lower Limit				STRING -> DOUBLE
 *      pcad->j = Default azimuth park position			STRING -> DOUBLE
 *      pcad->k = Default elevation park position		STRING -> DOUBLE
 *
 *  OUTPUTS:
 *      pcad->vala = Azimuth demand				(DOUBLE)
 *      pcad->valb = Elevation demand				(DOUBLE)
 *      pcad->valc = Set Az. command to MCS_PARK		(LONG)
 *      pcad->vald = Set El. command to MCS_PARK		(LONG)
 */

long parkCAD( struct cadRecord *pcad )
{
  double az;
  double el;
  long   debug;
  long   azDatum;
  long   elDatum;
  double azupper;
  double azlower;
  double elupper;
  double ellower;
  double azParkDef;
  double elParkDef;
  long   ret;
  long   useAzDef;
  long   useElDef;
  long   error;

  debug     = atol( (char *)pcad->c );
  azDatum   = atol( (char *)pcad->d );
  elDatum   = atol( (char *)pcad->e );
  azupper   = strtod( pcad->f, NULL );
  azlower   = strtod( pcad->g, NULL );
  elupper   = strtod( pcad->h, NULL );
  ellower   = strtod( pcad->i, NULL );
  azParkDef = strtod( pcad->j, NULL );
  elParkDef = strtod( pcad->k, NULL );
  az = strtod( pcad->a, NULL );
  el = strtod( pcad->b, NULL );
  ret      = CAD_ACCEPT;

  printf("parkDef = %f, %f\n",azParkDef,elParkDef);

  useAzDef  = 0;
  useElDef  = 0;

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 *  Clear the input arguments
 */
      printf ("IN CLEAR\n");
      strcpy( (char *)pcad->a, " ");
      strcpy( (char *)pcad->b, " ");
      db_post_events( pcad, &pcad->a, 1 );
      db_post_events( pcad, &pcad->b, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:

      /* Azimuth */

      error = check_numeric( pcad->a );
      if( error )
        printf("parkCAD: error = %ld from check_numeric for Az\n", error);
      if( error )
      {
        if( error == ALL_BLANKS )  /* Use the default park position */
        {
printf("Park: Use az default\n");
          useAzDef = 1;
          ret      = CAD_ACCEPT;
        }
        else
        {
          printf("Azimuth park position invalid\n");
          sprintf(pcad->mess, "Azimuth park position invalid");
          ret = CAD_REJECT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        if( azDatum == MCS_NOT_DATUMED )
        {
          sprintf( pcad->mess, "The azimuth axis has not been datumed" );
          ret = CAD_REJECT;
        }
        else
        {
          if( useAzDef )
            az = azParkDef;
          else
	  {
            az = strtod( pcad->a, NULL );
            printf("userDef AZ= %f\n",az);
          }
          if( debug )
            printf("parkCAD: az = %f, azlower = %f, azupper = %f\n", 
                    az, azlower, azupper);
          if( az < azlower )
          {
            sprintf(pcad->mess, "Az. demand %6.3f below limit (%6.3f)", az, azlower);
            ret = CAD_REJECT;
          }
          else if( az > azupper )
          {
            sprintf(pcad->mess, "Az. demand %6.3f above limit (%6.3f)", az, azupper);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      /* Elevation */

      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->b );
        if( error)
          printf("parkCAD: error = %ld from check_numeric for El\n", error);
        if( error )
        {
          if( error == ALL_BLANKS )  /* Use the default park position */
          {
            printf("Park: Use El default\n");
            useElDef = 1;
            ret      = CAD_ACCEPT;
          }
          else
          {
            sprintf(pcad->mess, "Elevation park position invalid");
            printf("Elevation park position invalid\n");
            ret = CAD_REJECT;
          }
        }
      }

      if( ret == CAD_ACCEPT )
      {
        if( elDatum == MCS_NOT_DATUMED )
        {
          sprintf( pcad->mess, "The elevation axis has not been datumed" );
          ret = CAD_REJECT;
        }
        else
        {
          if( useElDef )
            el = elParkDef;
          else
	  {
            el = strtod( pcad->b, NULL );
            printf("userDef EL= %f\n",el);
          }
          if( debug )
            printf("parkCAD: el = %f, ellower = %f, elupper = %f\n", 
                    el, ellower, elupper);
          if( el < ellower )
          {
            sprintf(pcad->mess, "El. Demand %6.3f below limit (%6.3f)", el, ellower);
            ret = CAD_REJECT;
          }
          else if( el > elupper )
          {
            sprintf(pcad->mess, "El. Demand %6.3f above limit (%6.3f)", el, elupper);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      printf("PARK requested: %f, %f",az,el);
      *(double *)pcad->vala = az;
      *(double *)pcad->valb = el;
      *(long *)pcad->valc = MCS_PARK;
      *(long *)pcad->vald = MCS_PARK;
        printf("Az. park position = %f, El. park position = %f\n",
               *(double *)pcad->vala, *(double *)pcad->valb);

      if( 1 )
        printf("Az. park position = %ld, El. park position = %ld\n",
               *(long *)pcad->vala, *(long *)pcad->valb);
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
epicsRegisterFunction(parkCAD);
