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
 *      pcad->a = Origin of command (TCS, ES, HP)			STRING -> LONG
 *      pcad->b = Hand Paddle command (AZUP, AZDOWN, ELUP, ELDOWN)	STRING -> LONG
 *      pcad->c = Azimuth Demand                        		STRING -> DOUBLE
 *      pcad->d = Elevation Demand                      		STRING -> DOUBLE
 *      pcad->e = Azimuth Velocity					STRING -> DOUBLE 
 *      pcad->f = Elevation Velocity					STRING -> DOUBLE
 *      pcad->g = Current Debug Level  0/1               		STRING -> LONG
 *      pcad->h = Azimuth Datum        0/1      			STRING -> LONG
 *      pcad->i = Elevation Datum      0/1	        		STRING -> LONG
 *      pcad->j = Azimuth Upper Limit					STRING -> DOUBLE
 *      pcad->k = Azimuth Lower Limit					STRING -> DOUBLE
 *      pcad->l = Elevation Upper Limit					STRING -> DOUBLE
 *      pcad->m = Elevation Lower Limit                			STRING -> DOUBLE
 *      pcad->n = Maximum Az. Velocity					STRING -> DOUBLE
 *      pcad->o = Maximum El. Velocity        				STRING -> DOUBLE
 *      pcad->p = Az Counts per degree                                  STRING -> LONG
 *      pcad->q = El Counts per degree                                  STRING -> LONG
 *      pcad->r = Not used
 *      pcad->s = Current maximum Az. Velocity		   	 	STRING -> DOUBLE
 *      pcad->t = Current maximum El. Velocity        			STRING -> DOUBLE
 *
 *  OUTPUTS:
 *      pcad->vala = String to set Azimuth Velocity            (STRING)
 *      pcad->valb = Azimuth jog string                        (STRING)
 *      pcad->valc = String to set Elevation Velocity          (STRING)
 *      pcad->vald = Elevation jog string      		       (STRING)
 *      pcad->vale = Mask for fanout record which drives axes  (LONG)
 *      pcad->valf = Not used
 *      pcad->valg = Set Az. command to MCS_MOVE               (LONG)
 *      pcad->valh = Set El. command to MCS_MOVE               (LONG)
 *      pcad->vali = Set current maximum azimuth velocity      (DOUBLE)
 *      pcad->valj = Set current maximum elevation velocity    (DOUBLE)
 */

long moveCAD( struct cadRecord *pcad )
{
  long   cmdOrig;
  long   hp;
  double az = 0;
  double el = 0;
  double azVel = 0;
  double elVel = 0;
  long   debug;
  long   azDatum;
  long   elDatum;
  double azupper;
  double azlower;
  double elupper;
  double ellower;
  double azMaxVel;
  double elMaxVel;
  long   azCountsPerDeg;
  long   elCountsPerDeg;
  double azCurrentMaxVel;
  double elCurrentMaxVel;
  long   ret = 0;
  long   moveAz;
  long   moveEl;
  long   useCurAzVel;
  long   useCurElVel;
  long   error;

  cmdOrig         = atol( (char *)pcad->a );
  hp              = atol( (char *)pcad->b );
  debug           = atol( (char *)pcad->g );
  azDatum         = atol( (char *)pcad->h );
  elDatum         = atol( (char *)pcad->i );
  azupper         = strtod( pcad->j, NULL );
  azlower         = strtod( pcad->k, NULL );
  elupper         = strtod( pcad->l, NULL );
  ellower         = strtod( pcad->m, NULL );
  azMaxVel        = strtod( pcad->n, NULL );
  elMaxVel        = strtod( pcad->o, NULL );
  azCountsPerDeg  = atol( (char *)pcad->p )/ECT;
  elCountsPerDeg  = atol( (char *)pcad->q )/ECT;
  azCurrentMaxVel = strtod( pcad->s, NULL );
  elCurrentMaxVel = strtod( pcad->t, NULL );

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 * Set default value on CLEAR.
 */
      strcpy( (char *)pcad->c, " ");
      strcpy( (char *)pcad->d, " ");
      strcpy( (char *)pcad->e, " ");
      strcpy( (char *)pcad->f, " ");
      db_post_events( pcad, &pcad->c, 1 );
      db_post_events( pcad, &pcad->d, 1 );
      db_post_events( pcad, &pcad->e, 1 );
      db_post_events( pcad, &pcad->f, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:

      /* First check the balance special case */
      if( cmdOrig == 3 )
      {
          strcpy( (char *)pcad->c, " ");
          db_post_events( pcad, &pcad->c, 1 );
	  cmdOrig = 1;
      }

      /* First deal with Hand Paddle moves. We don't care whether the axis has been datumed */
      if( cmdOrig == 2 )
      {
        if( hp == 1 )       /* Az +ve */
        {
          sprintf(pcad->vala, "I222 = %f", AZDEG_TO_I222*azCurrentMaxVel);
          strcpy(pcad->valb, "#2J+");
          strcpy(pcad->valc, "NO");
          strcpy(pcad->vald, " ");
          *(long *)pcad->vale = 1;
	  printf("Hand Paddle move command origen, Az +ve\n");
	  printf("command sent: I222 = %f, valb = #2J+\n", AZDEG_TO_I222*azCurrentMaxVel);
        }
        else if( hp == 2 )  /* Az -ve */
        {
          sprintf(pcad->vala, "I222 = %f", AZDEG_TO_I222*azCurrentMaxVel);
          strcpy(pcad->valb, "#2J-");
          strcpy(pcad->valc, "NO");
          strcpy(pcad->vald, " ");
          *(long *)pcad->vale = 1;
	  printf("Hand Paddle move command origen, Az -ve\n");
	  printf("command sent: I222 = %f, valb = #2J-\n", AZDEG_TO_I222*azCurrentMaxVel);
        }
        else if( hp == 3 )  /* El +ve */
        {
          strcpy(pcad->vala, "NO");
          strcpy(pcad->valb, " ");
          sprintf(pcad->valc, "I222 = %f", ELDEG_TO_I222*elCurrentMaxVel);
          strcpy(pcad->vald, "#2J+");
          *(long *)pcad->vale = 2;
	  printf("Hand Paddle move command origen, El +ve\n");
	  printf("command sent: I222 = %f, valb = #2J+\n", ELDEG_TO_I222*elCurrentMaxVel);
        }
        else if( hp == 4 )  /* El -ve */
        {
          strcpy(pcad->vala, "NO");
          strcpy(pcad->valb, " ");
          sprintf(pcad->valc, "I222 = %f", ELDEG_TO_I222*elCurrentMaxVel);
          strcpy(pcad->vald, "#2J-");
          *(long *)pcad->vale = 2;
	  printf("Hand Paddle move command origen, El -ve\n");
	  printf("command sent: I222 = %f, valb = #2J-\n", ELDEG_TO_I222*elCurrentMaxVel);
         
        }

        *(long *)pcad->valg = MCS_MOVE;
        *(long *)pcad->valh = MCS_MOVE;

        /* Set current max velocities */

        *(double *)pcad->vali = azCurrentMaxVel;
        *(double *)pcad->valj = elCurrentMaxVel;

        if( debug )
          printf("Az. Vel = %s, Az = %s, El. Vel = %s, El = %s, Mask = %ld\n",
                 (char *)pcad->vala, (char *)pcad->valb, (char *)pcad->valc, (char *)pcad->vald, *(long *)pcad->vale);
        return(0);
      }
          
      /* Engineering Screen and TCS moves and Balance move */

      /* Azimuth */

      error = check_numeric( pcad->c );
      if( debug )
        printf("moveCAD: error = %ld from check_numeric for Az\n", error);
      if( error )
      {
        moveAz = 0;
        if( error == ALL_BLANKS )  /* Move to same position */
          ret = CAD_ACCEPT;
        else
        {
          sprintf(pcad->mess, "Azimuth demand invalid");
          ret = CAD_REJECT;
        }
      }
      else
        moveAz = 1;

      /* We might have to move the axis, so check axis state */

      if( moveAz )
      {
	printf( "moveCAD: Azimuth: Engineering Screen and TCS move command origen\n");

        if( azDatum == MCS_NOT_DATUMED )
        {
          sprintf( pcad->mess, "The azimuth axis has not been datumed" );
          ret = CAD_REJECT;
        }
        else
        {
          az = strtod( pcad->c, NULL );
          /* if( debug )*/
            printf("moveCAD: az = %f, azlower = %f, azupper = %f\n", 
                    az, azlower, azupper);
          if( az < azlower )
          {
            sprintf(pcad->mess, "Az. Demand %6.3f below limit (%6.3f)", az, azlower);
            ret = CAD_REJECT;
          }
          else if( az > azupper )
          {
            sprintf(pcad->mess, "Az. Demand %6.3f above limit (%6.3f)", az, azupper);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      /* Elevation */

      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->d );
        if( debug )
          printf("moveCAD: error = %ld from check_numeric for El\n", error);
        if( error )
        {
          moveEl = 0;
          if( error == ALL_BLANKS )  /* Move to same position */
            ret = CAD_ACCEPT;
          else
          {
            sprintf(pcad->mess, "Elevation demand invalid");
            ret = CAD_REJECT;
          }
        }
        else
          moveEl = 1;

        /* We might have to move the axis, so check axis state */

        if( moveEl )
        {
	  printf( "moveCAD: Elevation: Engineering Screen and TCS move command origen\n");
          if( elDatum == MCS_NOT_DATUMED )
          {
            sprintf( pcad->mess, "The elevation axis has not been datumed" );
            ret = CAD_REJECT;
          }
          else
          {
            el = strtod( pcad->d, NULL );
            /* if( debug ) */
              printf("moveCAD: el = %f, ellower = %f, elupper = %f\n", 
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
      }

      /*  If this command was sent from an Engineering Screen, we should
       *  check the velocity parameters.
       */

      if( ret == CAD_ACCEPT )
      {
        if( cmdOrig == 1 )   /* Engineering Screen */
        {
          /* if(debug)*/
            printf("moveCAD: Command came from an Engineering Screen\n");

          /* First deal with Azimuth velocity */
          useCurAzVel = 0;
          error       = check_numeric( pcad->e );
          if( debug )
            printf("moveCAD: error = %ld from check_numeric for Az. Velocity\n", error);
          if( error )
          {
            if( error == ALL_BLANKS )  /* Use current velocity setting */
            {
              useCurAzVel = 1;
              ret         = CAD_ACCEPT;
            }
            else
            {
              sprintf(pcad->mess, "Azimuth velocity is invalid");
              ret = CAD_REJECT;
            }
          }

          if( (ret == CAD_ACCEPT) && !useCurAzVel )
          {
            azVel = strtod( pcad->e, NULL );
            if( debug )
              printf("moveCAD: azVel = %f, absMinAzVel = 0, absMaxAzVel = %f\n",
                      azVel, azMaxVel);
            if( azVel <= 0.0 )
            {
              sprintf(pcad->mess, "Max Az. Velocity cannot be <= 0.0 deg/s");
              ret = CAD_REJECT;
            }
            else if( azVel > azMaxVel )
            {
              sprintf(pcad->mess, "Az. Velocity %6.3f above limit (%6.3f)",
                      azVel, azMaxVel);
              ret = CAD_REJECT;
            }
            else
              ret = CAD_ACCEPT;
          }

          if( ret == CAD_ACCEPT )
          {
            /* Now deal with Elevation velocity */
            useCurElVel = 0;
            error       = check_numeric( pcad->f );
            if( debug )
              printf("moveCAD: error = %ld from check_numeric for El. Velocity\n", error);
            if( error )
            {
              if( error == ALL_BLANKS )  /* Use current velocity setting */
              {
                useCurElVel = 1;
                ret         = CAD_ACCEPT;
              }
              else
              {
                sprintf(pcad->mess, "Elevation velocity is invalid");
                ret = CAD_REJECT;
              }
            }

            if( (ret == CAD_ACCEPT) && !useCurElVel )
            {
              elVel = strtod( pcad->f, NULL );
              if( debug )
                printf("moveCAD: elVel = %f, absMinElVel = 0, absMaxElVel = %f\n",
                        elVel, elMaxVel);
              if( elVel <= 0.0 )
              {
                sprintf(pcad->mess, "Max El. Velocity cannot be <= 0.0 deg/s");
                ret = CAD_REJECT;
              }
              else if( elVel > elMaxVel )
              {
                sprintf(pcad->mess, "El. Velocity %6.3f above limit (%6.3f)",
                        elVel, elMaxVel);
                ret = CAD_REJECT;
              }
              else
                ret = CAD_ACCEPT;
            }
          }
        }
        else   /* Command came from the TCS */
        {
          /* if(debug) */
            printf("moveCAD: Command came from the TCS\n");
          useCurAzVel = 2;
          useCurElVel = 2;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        switch( useCurAzVel )
        {
          case 0:
            sprintf(pcad->vala, "I222 = %f", AZDEG_TO_I222*azVel);
            *(double *)pcad->vali = azVel;
            break;

          case 1:
            sprintf(pcad->vala, "I222 = %f", AZDEG_TO_I222*azCurrentMaxVel);
            *(double *)pcad->vali = azCurrentMaxVel;
            break;

          case 2:
            sprintf(pcad->vala, "I222 = %f", AZDEG_TO_I222*azMaxVel);
            *(double *)pcad->vali = azMaxVel;
            break;

          default:
            printf("moveCAD: Error in setting of useCurAzVel = %ld\n", useCurAzVel);
            break;
        }

        switch( useCurElVel )
        {
          case 0:
            sprintf(pcad->valc, "I222 = %f", ELDEG_TO_I222*elVel);
            *(double *)pcad->valj = elVel;
            break;

          case 1:
            sprintf(pcad->valc, "I222 = %f", ELDEG_TO_I222*elCurrentMaxVel);
            *(double *)pcad->valj = elCurrentMaxVel;
            break;

          case 2:
            sprintf(pcad->valc, "I222 = %f", ELDEG_TO_I222*elMaxVel);
            *(double *)pcad->valj = elMaxVel;
            break;

          default:
            printf("moveCAD: Error in setting of useCurElVel = %ld\n", useCurElVel);
            break;
        }

        if( moveAz && moveEl )
        {
          sprintf(pcad->valb, "#2J=%ld", (long)(azCountsPerDeg*az) );
          sprintf(pcad->vald, "#2J=%ld", (long)(elCountsPerDeg*el) );
          *(long *)pcad->vale = 3;
          *(long *)pcad->valg = MCS_MOVE;
          *(long *)pcad->valh = MCS_MOVE;
        }
        else if( moveAz && !moveEl )
        {
          sprintf(pcad->valb, "#2J=%ld", (long)(azCountsPerDeg*az) );
          strcpy(pcad->vald, " " );
          *(long *)pcad->vale = 1;
          *(long *)pcad->valg = MCS_MOVE;
        }
        else if( !moveAz && moveEl )
        {
          sprintf(pcad->valb, " " );
          sprintf(pcad->vald, "#2J=%ld", (long)(elCountsPerDeg*el) );
          *(long *)pcad->vale = 2;
          *(long *)pcad->valh = MCS_MOVE;
        }
        else if( !moveAz && !moveEl )
        {
          sprintf(pcad->valb, " " );
          sprintf(pcad->vald, " " );
          *(long *)pcad->vale = 4;
        }

      }

      /* Leave the default command origin as the TCS */

      strcpy( (char *)pcad->a, "0");
      db_post_events( pcad, &pcad->a, 1 );

      /* if( debug ) */
        printf("Az. Vel = %s, Az = %s, El. Vel = %s, El = %s, Mask = %ld\n",
               (char *)pcad->vala, (char *)pcad->valb, (char *)pcad->valc, (char *)pcad->vald, *(long *)pcad->vale);

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
epicsRegisterFunction(moveCAD);
