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
#include <menuCarstates.h>
#include <mcssir.h>
#include <mcs.h>
#include <caLogDataDriver.h>

double calMaxFreq( long, long, long, double, double, double );

/* 
 *  INPUTS:
 *      pcad->a = Root of filename                      STRING -> STRING
 *      pcad->b = Requested Logging Frequency           STRING -> DOUBLE
 *      pcad->c = Start Time (seconds from now)         STRING -> LONG
 *      pcad->d = Duration (seconds)                    STRING -> LONG
 *      pcad->e = Data ID                               STRING -> STRING
 *      pcad->f = Current Debug Level 0/1               STRING -> LONG
 *      pcad->g = Azimuth PMAC Servo Frequency          STRING -> DOUBLE
 *      pcad->h = Elevation PMAC Servo Frequency        STRING -> DOUBLE
 *      pcad->i = Counterweights PMAC Servo Frequency   STRING -> DOUBLE
 *      pcad->j = Current logDataL state (SIR)          STRING -> LONG
 *      pcad->k = unused
 *      pcad->l = Azimuth time reference                STRING -> LONG
 *      pcad->m = Elevation time reference              STRING -> LONG
 *      pcad->n = Counterweights time reference         STRING -> LONG
 *
 *  OUTPUTS:
 *      pcad->vala = Actual Azimuth logging frequency                      (DOUBLE)
 *      pcad->valb = Number of servo cycles at which to log Azimuth Data   (LONG)
 *      pcad->valc = Actual Elevation logging frequency                    (DOUBLE)
 *      pcad->vald = Number of servo cycles at which to log Elevation Data (LONG)
 *      pcad->vale = Actual Counterweights logging frequency               (DOUBLE)
 *      pcad->valf = Number of servo cycles at which to log C/W Data       (LONG)
 *      pcad->valg = Root of filename                                      (STRING)
 *      pcad->valh = Start Time (seconds)                                  (LONG)
 *      pcad->vali = Stop Time (seconds)                                   (LONG)
 *      pcad->valj = Data ID                                               (STRING)
 *      pcad->valk = Binary Mask - which PMAC's are involved 0-7           (LONG)
 *                   AZ = 1
 *                   EL = 2
 *                   CW = 4
 *      pcad->vall = Start/Stop Binary Mask 0-7                            (LONG)
 *                   Start Now         -> Stop on button   = 1
 *                   Start Now         -> Stop after delay = 5
 *                   Start after delay -> Stop on button   = 2
 *                   Start after delay -> Stop after delay = 6
 *
 */

/* These are the default values which will be used if an argument is blank */

#define DEFAULT_FILENAME   "xxx"
#define DEFAULT_FREQUENCY  20
#define DEFAULT_START      0
#define DEFAULT_DURATION   0
#define DEFAULT_DATASET    "USERS_CHOICE"


long logDataCAD( struct cadRecord *pcad )
{
  char   rootFile[MAX_STRING_SIZE];
  double logFreq;
  long   startTime;
  long   stopTime;
  long   duration;
  char   dataID[MAX_STRING_SIZE];
  long   debug;
  double azServoFreq;
  double elServoFreq;
  double cwServoFreq;
  long   logState;
  long   ret = 0;
  char   str[MAX_STRING_SIZE];
  long   azFlag;
  long   elFlag;
  long   cwFlag;
  double max;
  long   ncycles;
  long   error;
  long   pmacMask = 0;
  long   azTimeRef;
  long   elTimeRef;
  long   cwTimeRef;

  /* These are read from database links */
  debug        = atol( (char *)pcad->f );
  azServoFreq  = strtod( pcad->g, NULL );
  elServoFreq  = strtod( pcad->h, NULL );
  cwServoFreq  = strtod( pcad->i, NULL );
  logState     = atol( (char *)pcad->j );
  azTimeRef    = atol( (char *)pcad->l );
  elTimeRef    = atol( (char *)pcad->m );
  cwTimeRef    = atol( (char *)pcad->n );

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      ret = CAD_ACCEPT;
      if( logState == MCS_LOG_PRIMED )
      {
        sprintf(pcad->mess, "Logging PRIMED - hit CLEAR to cancel");
        ret = CAD_REJECT;
      }
      else if( logState == MCS_LOG_ON )
      {
        sprintf(pcad->mess, "Logging in progress - hit STOP to end");
        ret = CAD_REJECT;
      }

      if( ret == CAD_ACCEPT )
      {
        error = check_string(pcad->a, rootFile, MAX_STRING_SIZE, 0);
        if( error == ALL_BLANKS )
        {
          strcpy(rootFile, DEFAULT_FILENAME);
          strcpy(pcad->a, rootFile);
          db_post_events(pcad, pcad->a, 1);
        }
        else if( error == TOO_LONG )
        {
          sprintf(pcad->mess, "Filename too long");
          ret = CAD_REJECT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->b );
        if( debug )
          printf("logDataCAD: error = %ld from check_numeric for logging freq\n", error);
        if( error )
        {
          if( error == ALL_BLANKS )
          {
            logFreq = DEFAULT_FREQUENCY;
            sprintf(pcad->b, "%f", logFreq);
            db_post_events(pcad, pcad->b, 1);
          }
          else
          {
            sprintf(pcad->mess, "Logging frequency not numeric");
            ret = CAD_REJECT;
          }
        }
        else
        {
          logFreq = strtod( pcad->b, NULL );
          if( logFreq <= 0.0 )
          {
            sprintf(pcad->mess, "Logging frequency invalid");
            ret = CAD_REJECT;
          }
        }

        if( ret == CAD_ACCEPT )
        {
          error = check_numeric( pcad->c );
          if( debug )
            printf("logDataCAD: error = %ld from check_numeric for start time\n", error);
          if( error )
          {
            if( error == ALL_BLANKS )
            {
              startTime = DEFAULT_START;
              sprintf(pcad->c, "%ld", startTime);
              db_post_events(pcad, pcad->c, 1);
            }
            else
            {
              sprintf(pcad->mess, "Start time not numeric");
              ret = CAD_REJECT;
            }
          }
          else
          {
            startTime = atol( (char *)pcad->c );
            if( startTime < 0 )
            {
              sprintf(pcad->mess, "Start time invalid");
              ret = CAD_REJECT;
            }
          }
        }

        if( ret == CAD_ACCEPT )
        {
          error = check_numeric( pcad->d );
          if( debug )
            printf("logDataCAD: error = %ld from check_numeric for duration\n", error);
          if( error )
          {
            if( error == ALL_BLANKS )
            {
              duration = DEFAULT_DURATION;
              sprintf(pcad->d, "%ld", duration);
              db_post_events(pcad, pcad->d, 1);
              stopTime = startTime;
            }
            else
            {
              sprintf(pcad->mess, "Duration not numeric");
              ret = CAD_REJECT;
            }
          }
          else
          {
            duration = atol( (char *)pcad->d );
            if( duration < 0.0 )
            {
              sprintf(pcad->mess, "Duration invalid");
              ret = CAD_REJECT;
            }
            else 
              stopTime = startTime + duration;
          }
        }

        if( ret == CAD_ACCEPT )
        {
          error = check_string(pcad->e, str, MAX_STRING_SIZE, 1);
          if( error == ALL_BLANKS )
          {
            strcpy(str, DEFAULT_DATASET);
            strcpy(pcad->e, str);
            db_post_events(pcad, pcad->e, 1);
          }
          else if( error == TOO_LONG )
          {
            sprintf( pcad->mess, "Data ID field too long" );
            ret = CAD_REJECT;
          }
          else if( !strcmp(str, "USERS_CHOICE") )
          {
            if( debug )
              printf("logDataCAD - PRESET: Setting Data ID to USERS_CHOICE\n");
            strcpy( dataID, str );

            /* Read the current logging set-up to determine which PMAC cards
               are involved in data logging */

            caReadLogSetup( &azFlag, &elFlag, &cwFlag );
            pmacMask  = 4*cwFlag + 2*elFlag + azFlag;
          }
          else if( !strcmp(str, "DATASET1") || !strcmp(str, "DATASET2") ||
                   !strcmp(str, "DATASET3") || !strcmp(str, "DATASET4") )
          {
            if( debug )
              printf("logDataCAD - PRESET: Setting Data ID to %s\n", str);
            strcpy( dataID, str );
            readDataSet( &azFlag, &elFlag, &cwFlag, str );
            pmacMask  = 4*cwFlag + 2*elFlag + azFlag;
          }
          else
          {
            sprintf( pcad->mess, "%s: Not a valid Data ID", str );
            ret = CAD_REJECT;
          }
        }

        /* Now check that the frequency requested is not too high */

        if( ret == CAD_ACCEPT )
        {
          max = calMaxFreq( azFlag, elFlag, cwFlag, azServoFreq, elServoFreq, cwServoFreq );
          if( max < 0 )
          {
            strcpy(pcad->mess, "No Data Specified");
            ret = CAD_REJECT;
          }
          else if( logFreq > max ) 
          {
            sprintf(pcad->mess, "Log frequency too high (> %6.2f)", max);
            ret = CAD_REJECT;
          }
        }

        /* Finally, check that time reference values are available for each
           PMAC card */

        if( ret == CAD_ACCEPT )
        {
          if( !azTimeRef )
          {
            strcpy(pcad->mess, "No Azimuth Time Reference");
            ret = CAD_REJECT;
          }
          else if( !elTimeRef )
          {
            strcpy(pcad->mess, "No Elevation Time Reference");
            ret = CAD_REJECT;
          }
          else if( !cwTimeRef )
          {
            strcpy(pcad->mess, "No Counterweights Time Reference");
            ret = CAD_REJECT;
          }
        }

        if( ret == CAD_ACCEPT )
        {
          /* If we get here, we've passed all the tests to accept the logData command */
          /* 'ncycles' will be the I-variable representing the No. Servo cycles       */

          ncycles               = (long)((azServoFreq/logFreq));
          *(double *)pcad->vala = azServoFreq/ncycles;
          *(long *)pcad->valb   = ncycles;
          ncycles               = (long)((elServoFreq/logFreq));
          *(double *)pcad->valc = elServoFreq/ncycles;
          *(long *)pcad->vald   = ncycles;
          ncycles               = (long)((cwServoFreq/logFreq));
          *(double *)pcad->vale = cwServoFreq/ncycles;
          *(long *)pcad->valf   = ncycles;
          strcpy(pcad->valg, rootFile);
          *(long *)pcad->valh   = startTime;
          *(long *)pcad->vali   = stopTime;
          strcpy(pcad->valj, dataID);
          *(long *)pcad->valk   = pmacMask;
          if( !startTime && !duration )
            *(long *)pcad->vall = 1;
          else if( !startTime && duration )
            *(long *)pcad->vall = 5;
          else if( startTime && !duration )
            *(long *)pcad->vall = 2;
          else if( startTime && duration )
            *(long *)pcad->vall = 6;

          if( strcmp(dataID, "USERS_CHOICE") )
            caWriteLogSetup( dataID );
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


double calMaxFreq( long azFlag, long elFlag, long cwFlag, 
                   double azServo, double elServo, double cwServo )
{
  double ret;

  if( azFlag && elFlag && cwFlag )
  {
    ret = azServo;
    if( elServo < ret )
      ret = elServo;
    if( cwServo < ret )
      ret = cwServo;
  }
  else if( azFlag && elFlag && !cwFlag )
  {
    ret = azServo;
    if( elServo < ret )
      ret = elServo;
  }
  else if( azFlag && !elFlag && cwFlag )
  {
    ret = azServo;
    if( cwServo < ret )
      ret = cwServo;
  }
  else if( azFlag && !elFlag && !cwFlag )
    ret = azServo;
  else if( !azFlag && elFlag && cwFlag )
  {
    ret = elServo;
    if( cwServo < ret )
      ret = cwServo;
  }
  else if( !azFlag && elFlag && !cwFlag )
    ret = elServo;
  else if( !azFlag && !elFlag && cwFlag )
    ret = cwServo;
  else if( !azFlag && !elFlag && !cwFlag )
    ret = -1.0;

  return( ret );
}
epicsRegisterFunction(logDataCAD);
