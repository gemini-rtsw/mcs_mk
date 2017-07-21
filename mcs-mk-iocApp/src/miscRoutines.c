#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsPrint.h>
#include <epicsThread.h>
#include <ctype.h>
#include <unistd.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <subRecord.h>
#include <genSubRecord.h>
#include <sirRecord.h>
#include <mcssir.h>
#include <mcscad.h>
#include <mcs.h>
#include <drvPmac.h>

#include <cadRecord.h>
#include <cad.h>
#include <menuCarstates.h>
#include <timeLib.h>

int logTrajFlag = 0;

struct logPmacTraj {
    double azDemandPos;
    double azPmacDemandPos;
    double azCurrentPos;
    double azCurrentVel;
    double elDemandPos;
    double elPmacDemandPos;
    double elCurrentPos;
    double elCurrentVel;
};

struct logPmacTraj logAxisTraj[10000];
int    logDisCounter = 0;

void dumpTraj();
void logTrajClean();
void logTrajEnable();
void logTrajDisable();

/* 
 *  This routine exists because subroutine records need an
 *  initialisation routine
 */

long nullSub( struct subRecord *psub )
{
  return(0);
}


/*  This routine reboots the MCS
 */

long rebootSub( struct subRecord *psub )
{
/*  reboot(BOOT_CLEAR); */
  return(0);
}


/* 
 *  This function strips off any leading white space and
 *  converts to upper case if "conv" is 1.
 */

long check_string( char *input, char *output, int len, int conv )
{
  char *str1;
  long ret;
  int  i;

  if( strlen(input) > len )
  {
    str1 = (char *)strtok(input, " ");
    if( (str1 == NULL) || (str1[0] == ' ') )
      ret = ALL_BLANKS;
    else
      ret = TOO_LONG;
  }
  else
  {
    str1 = (char *)strtok(input, " ");
    if( (str1 == NULL) || (str1[0] == ' ') )
      ret = ALL_BLANKS;
    else
    {
      strcpy(output, str1);
      if( conv )
      {
        i    = 0;
        str1 = output;
        while(*str1)
        {
          output[i++] = toupper((int)*str1);
          str1++;
        }
      }
      ret = 0;
    }
  }
  return(ret);
}


/* 
 *  This function checks that an argument to a CAD record is numeric
 */

long check_numeric( char *buf )
{
  char *c;
  int  len;
  int  i;
  int  ret;
  int  istart;
  int  iend;
  int  numEs;
  int  numDots;

  numEs   = 0;
  numDots = 0;
  istart  = 0;
  ret     = 0;
  len     = strlen(buf);
  c       = buf;
  while( isspace((int)*c) )
  {
    c++;
    istart++;
  }
  if( istart == len )
  {
    /* Case of all blanks */
    ret = ALL_BLANKS;
  }
  else
  { 
    /* At this point istart refers to the first non-space character */
    iend = istart;
    while( !isspace((int)*c) && iend<len )
    {
      c++;
      iend++;
    }
    /* iend is one past the last non-space character */
    /* This is necessary because we must go round the loop at least once */
    c = buf;
    for( i=istart; i<iend; i++ )
    {
      if( i == istart )
      {
        /* Allow '+' and '-' and '.' as first character */
        if( !isdigit((int)*(c+i)) && (*(c+i) != '-') && (*(c+i) != '+') && (*(c+i) != '.') )
        {
          ret = SYNTAX_ERROR;
          break;
        }
        /* Reject the case of a single '+' or '-'  or '.' with no following digits */
        if( (iend-istart == 1) && ((*(c+i) == '-') || (*(c+i) == '+') || (*(c+i) == '.')) )
        {
          ret = SYNTAX_ERROR;
          break;
        }
      }
      else
      {
        if( !isdigit((int)*(c+i)) && (*(c+i) != '.') &&
             (*(c+i) != 'E') && (*(c+i) != 'e') && 
             (*(c+i) != '+') && (*(c+i) != '-') )
        {
          ret = SYNTAX_ERROR;
          break;
        }
        else if( *(c+i) == '.' )
        {
          numDots++;
          if( numDots > 1 )
          {
            ret = SYNTAX_ERROR;
            break;
          }
        }
        else if( (*(c+i) == 'E') || (*(c+i) == 'e') )
        {
          numEs++;
          if( numEs > 1 )
          {
            ret = SYNTAX_ERROR;
            break;
          }
        }
        if( *(c+i) == '.' )
        {
          if( (*(c+i-1) != '+') && (*(c+i-1) != '-') && !isdigit((int)*(c+i-1)) )
          {
            ret = SYNTAX_ERROR;
            break;
          }
        }
        if( (*(c+i) == 'E') || (*(c+i) == 'e') )
        {
          if( (*(c+i-1) != '.') && !isdigit((int)*(c+i-1)) )
          {
            ret = SYNTAX_ERROR;
            break;
          }
        }
        if( (*(c+i) == '+') || (*(c+i) == '-') )
        {
          if( (*(c+i-1) != 'e') && (*(c+i-1) != 'E') )
          {
            ret = SYNTAX_ERROR;
            break;
          }
        }
      }
    }
  }
  return ret;
}


/*  This routine sets the mask which is used to determine which 
 *  links are processed on the decode simulation sequence record.
 *
 *  INPUTS:
 *	psub->a = Simulation Level  NONE/VSM/FAST/FULL    (DOUBLE).
 *      psub->b = Debug Level       0/1                   (DOUBLE).
 *
 *  OUTPUTS:
 *	psub->val = Mask (from table below, see "simmDecode.sch") (DOUBLE).
 *
 *				        Links
 *		  Simulation Level   1  2  3  4
 *                -----------------------------
 *			    NONE     0  0  0  1  = 8
 *			    VSM      1  0  0  0  = 1
 *			    FAST     0  1  0  0  = 2
 *			    FULL     0  0  1  0  = 4
 */

long setMask( struct subRecord *psub )
{
  long simmLevel;
  long debug;

  simmLevel = (long)psub->a;
  debug     = (long)psub->b;
  switch( simmLevel )
  {
    case MCS_NONE:
      psub->val = 8;
      break; 

    case MCS_VSM:
      psub->val = 1;
      break; 

    case MCS_FAST:
      psub->val = 2;
      break; 

    case MCS_FULL:
      psub->val = 4;
      break; 

    default:
      printf("Unknown simulation level %ld - Assuming VSM\n", simmLevel);
      psub->val = 1;
      break;
  }
  if( debug )
    printf("setMask: Simulation Mode %ld, setting mask to %ld\n", 
            simmLevel, (long)psub->val );

  return(0);
}


/* Reports the current directory to 'dm' and          */
/* picks out the version of the MCS which is running  */

long pwdCommand( struct genSubRecord *pgsub )
{
  int  i;
  char *res;
  char buffer[MAX_STRING_SIZE];

  res = getcwd(buffer, MAX_STRING_SIZE);
  if( !res )
    sprintf(pgsub->vala, "Pathname longer than %d characters", MAX_STRING_SIZE);
  else
  {
    strcpy(pgsub->vala, buffer);
    res = (char *)strtok(buffer, "/");
    i   = 0;
    while( i<3 )
    {
      res = (char *)strtok(NULL, "/");
      i++;
    }
    strcpy(pgsub->valb, res);
  }

  return(0);
}


/*
 * Converts Decimal to Hex.
 */

char *decTohex(int a, int b, int c, int d)
{
  int         ans;
  static char *ret = NULL;
   
  if(!ret)
    ret = malloc(2);

  ans = d + 2*c + 4*b + 8*a;
  if(ans==0)
    strcpy(ret, "0");
  else if(ans==1)
    strcpy(ret, "1");
  else if(ans==2)
    strcpy(ret, "2");
  else if(ans==3)
    strcpy(ret, "3");
  else if(ans==4)
    strcpy(ret, "4");
  else if(ans==5)
    strcpy(ret, "5");
  else if(ans==6)
    strcpy(ret, "6");
  else if(ans==7)
    strcpy(ret, "7");
  else if(ans==8)
    strcpy(ret, "8");
  else if(ans==9)
    strcpy(ret, "9");
  else if(ans==10)
    strcpy(ret, "A");
  else if(ans==11)
    strcpy(ret, "B");
  else if(ans==12)
    strcpy(ret, "C");
  else if(ans==13)
    strcpy(ret, "D");
  else if(ans==14)
    strcpy(ret, "E");
  else if(ans==15)
    strcpy(ret, "F");
  else
    strcpy(ret, " ");

  return ret;
}


/* This routine resets a delay */

long delayReset( struct genSubRecord *pgsub )
{
  strcpy(pgsub->vala, "Passive");
  return(0);
}


/* This routine is called when a delay is set-up */

long delayStart( struct genSubRecord *pgsub )
{
  *(double *)pgsub->valb = 1;

  if( *(long *)pgsub->j == 0 )
    strcpy(pgsub->valc, "Passive");
  else
  {
    *(double *)pgsub->vala = *(long *)pgsub->i;
    strcpy(pgsub->valc, "1 second");
  }

  return(0);
}


long handPaddleStop( struct genSubRecord *pgsub )
{
  long azState;
  long elState;
  long azStop;
  long elStop;

  azState = *(long *)pgsub->a;
  elState = *(long *)pgsub->b;

  if( (azState != MCS_STATIONARY) && (azState != MCS_BRAKED) )
    azStop = 1;
  else
    azStop = 0;

  if( (elState != MCS_STATIONARY) && (elState != MCS_BRAKED) )
    elStop = 1;
  else
    elStop = 0;

  if( azStop && !elStop )
    strcpy(pgsub->vala, "AZ");
  else if( !azStop && elStop )
    strcpy(pgsub->vala, "EL");
  else
    strcpy(pgsub->vala, "BOTH");

  strcpy(pgsub->valb, "NO");
  strcpy(pgsub->valc, "NO");

  return(0);
}


long setErrorString( struct genSubRecord *pgsub )
{
  long errornumber;

  errornumber = (long)(*(double *)pgsub->a);

  switch( errornumber )
  {
    case 1:
      strcpy(pgsub->vala, "Interlock");
      break;

    case 2:
      strcpy(pgsub->vala, "GIS failed to set brakes");
      break;

    case 3:
      strcpy(pgsub->vala, "Unimplemented feature of the MCS");
      break;

    case 4:
      strcpy(pgsub->vala, "Datum failed - try again");
      break;

    default:
      strcpy(pgsub->vala, "Unspecified Error");
      break;
  }
  return(0);
}


long setErrorString1( struct genSubRecord *pgsub )
{
  strcpy( pgsub->vala, pgsub->a );
  return(0);
}


long vecntsTodeg( struct sirRecord *psir )
{
  double denom;

#ifdef TELESCOPE
  denom = 720000.0;
#else
  denom = 16667.0;
#endif
  *(double *)psir->val = (*(double *)psir->rval)/denom;
  return(0);
}


long GISdebugInit( struct subRecord *psub )
{
  char str1[64];
  char str2[16];

  if( psub->a == 0 )
    strcpy(str2, " FAULT HIGH");
  else if( psub->a == 1 )
    strcpy(str2, " DISASSERTED");
  else if( psub->a == 2 )
    strcpy(str2, " ASSERTED");
  else if( psub->a == 3 )
    strcpy(str2, " FAULT LOW");

  if( (!psub->c) && (!psub->b) )
    strcpy(str1, "iocInit: Azimuth Drive Condition set to");
  else if( (!psub->c) && (psub->b) )
    strcpy(str1, "iocInit: Azimuth Drive Enable set to");
  else if( (psub->c) && (!psub->b) )
    strcpy(str1, "iocInit: Elevation Drive Condition set to");
  else if( (psub->c) && (psub->b) )
    strcpy(str1, "iocInit: Elevation Drive Enable set to");

/*
  printf("%s %s\n", str1, str2);
*/

  return(0);
}


long GISdebug( struct subRecord *psub )
{
  char str1[64];
  char str2[16];

  if( psub->a == 0 )
    strcpy(str2, " FAULT HIGH");
  else if( psub->a == 1 )
    strcpy(str2, " DISASSERTED");
  else if( psub->a == 2 )
    strcpy(str2, " ASSERTED");
  else if( psub->a == 3 )
    strcpy(str2, " FAULT LOW");

  if( (!psub->c) && (!psub->b) )
    strcpy(str1, "Azimuth Drive Condition set to");
  else if( (!psub->c) && (psub->b) )
    strcpy(str1, "Azimuth Drive Enable set to");
  else if( (psub->c) && (!psub->b) )
    strcpy(str1, "Elevation Drive Condition set to");
  else if( (psub->c) && (psub->b) )
    strcpy(str1, "Elevation Drive Enable set to");

/*
  printf("%s %s\n", str1, str2);
*/

  return(0);
}


long speedControl( struct genSubRecord *pgsub )
{
  long   terminator;
  long   ret;
  long   card;
  char   command[MAX_STRING_SIZE];
  char   response[MAX_STRING_SIZE];
  char   errmsg[MAX_STRING_SIZE];
  double speed;

  speed  = *(double *)pgsub->a;
  card   = (long)(*(double *)pgsub->b);
  speed *= 10;

  if( *((char *)pgsub->j) == '+' )
    sprintf(command, "#2o%.2f", speed);
  else if( *((char *)pgsub->j) == '-' )
    sprintf(command, "#2o-%.2f", speed);
  else if( *((char *)pgsub->j) == 'K' )
    strcpy(command, "#2K");

  terminator = drvPmacMbxWriteRead(card, command, response, errmsg);
  if( errmsg[0] )
  {
    printf("PMAC command = %s,  Error: %s\n", command, errmsg);
    ret = 1;
  }

  return(ret);
}


long SendJog( struct genSubRecord *pgsub )
{
  long ret;
  long card;
  long debug;
  long terminator;
  char response[MAX_STRING_SIZE];
  char errmsg[MAX_STRING_SIZE];

  ret   = 0;
  card  = (long)(*(double *)pgsub->c);
  debug = (long)(*(double *)pgsub->d);

  if( strcmp((char *)pgsub->b, "NO") )   /* Set the velocity if required */
  {
    /* if( debug ) */
      printf("SendJog: Setting Velocity with: %s\n", (char *)pgsub->b);
    terminator = drvPmacMbxWriteRead(card, pgsub->b, response, errmsg);
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->b, errmsg);
      ret = 1;
    }
  }

  if( !ret )  /* Send the Jog */
  {
    /* if( debug ) */
      printf("SendJog: Sending jog: %s\n", (char *)pgsub->a);
    terminator = drvPmacMbxWriteRead(card, pgsub->a, response, errmsg);
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->a, errmsg);
      ret = 1;
    }
  }

  printf("Enabling the endMove routine \n");
  *(long *)pgsub->vala = 1;  /* Enable the endMove routine */

  return(ret);
}

/* End Move Command. The record calling this routine processes
 * every five seconds.
 *
 * Inputs:
 *      pgsub->a = move in progress flag (0: 1= MCS_MOVE)
 *	pgsub->b = last command issued (e.g. MCS_MOVE)
 *	pgsub->c = axis to move (0=az, 1=el)
 *	pgsub->d = debug level	
 *	pgsub->e = desired velocity zero
 *	pgsub->f = in position
 *	pgsub->g = internal use
 *
 * Outputs:
 *	pgsub->vala = select mask (0=not done, 3=done)
 *	pgsub->valb = Move flag (0, 1)
 *
 */
long endMove (struct genSubRecord *pgsub)
{
    long   cmd;
    long   card;
    long   debug;
    long   dvz;
    long   inpos;

    cmd       = *(long *) pgsub->b;
    card      =  (long)(*(double *) pgsub->c);
    debug     = *(long *) pgsub->d;
    dvz       = *(long *) pgsub->e;
    inpos     = *(long *) pgsub->f;

    /* Process only if the last command was MOVE, if the desired velocity
     * is zero, and if we are in position.
     */
    if ((cmd == MCS_MOVE) && dvz && inpos)
    {
	if (debug)
	    printf("endMove: Setting CAR to IDLE\n");

	/* Set sequence mask to mark move completed.
	 */
	*(long *) pgsub->vala = 3;

	/* Set the Move Flag to True.
	 */
	*(long *) pgsub->valb = 1;

	/* Set internal flag back to 0 (FALSE).
	 */
	*(long *) pgsub->a = 0;
    }
    else
    {
	*(long *) pgsub->vala = 0;	/* datum didn't process */
	if (debug)
	    printf ("endMove: Do nothing\n");
    }

    return(0);
}

long torqueCalc( struct genSubRecord *pgsub )
{
  int    i;
  double motor1;
  double motor2;
  double motor3;
  double motor4;
  double totalTorque;
  static int    ii = 0;
  static double torque[10];

  motor1 = *(double *)pgsub->a;
  motor2 = *(double *)pgsub->b;
  motor3 = *(double *)pgsub->c;
  motor4 = *(double *)pgsub->d;

  torque[ii] = ((motor1+motor2+motor3+motor4)*16.0*42.0)/10.0;
  ii++;
  ii = ii%10;

  totalTorque = 0;
  for( i=0; i<10; i++ )
    totalTorque += torque[i];

  *(double *)pgsub->vala = totalTorque/10.0;

  return(0);
}

/*
 * This routine performs the remaining slew time calculation at 1 Hz.
 *
 * INPUTS:
 *      pgsub->a = Azimuth Position Error (Degrees)             (DOUBLE).
 *      pgsub->b = Elevation Position Error (Degrees)           (DOUBLE).
 *      pgsub->c = Azimuth Current Velocity (Degrees/second)    (DOUBLE).
 *      pgsub->d = Elevation Current Velocity (Degrees/second)  (DOUBLE).
 *      pgsub->e = New trackId                                  (DOUBLE).
 *
 * OUTPUTS:
 *      pgsub->vala = Remaining Slew Time                       (DOUBLE).
 */

long slewTimeCalc( struct genSubRecord *pgsub )
{
  double azPosError;
  double elPosError;
  double azVelocity;
  double elVelocity;
  double trackId;
  /*static int first = 1;
  static double prevTrackId; */
  long   mask;

  azPosError = *(double *)pgsub->a;
  elPosError = *(double *)pgsub->b;
  azVelocity = *(double *)pgsub->c;
  elVelocity = *(double *)pgsub->d;
  trackId    = *(double *)pgsub->e;

  mask       = 0;


  return(0);
}

long startSlew( struct genSubRecord *pgsub )
{
  long ret;
  long debug;
  long terminator;
  char response[MAX_STRING_SIZE];
  char errmsg[MAX_STRING_SIZE];

  ret   = 0;
  debug = (long)(*(double *)pgsub->a);

  /* Set Azimuth velocity */

  if( strcmp((char *)pgsub->d, "NO") )   /* Set the velocity if required */
  {
    printf("SendJog: Setting Azimuth Velocity with: %s\n", (char *)pgsub->d);
    terminator = drvPmacMbxWriteRead(0, pgsub->d, response, errmsg); 
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->d, errmsg);
      ret = 1;
    }
  }

  /* Set Elevation velocity */

  if( strcmp((char *)pgsub->e, "NO") )   /* Set the velocity if required */
  {
    printf("SendJog: Setting Elevation Velocity with: %s\n", (char *)pgsub->e);
    terminator = drvPmacMbxWriteRead(1, pgsub->e, response, errmsg); 
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->e, errmsg);
      ret = 1;
    }
  }

  if( !ret )  /* Send the Azimuth Jog */
  {
    printf("SendJog: Sending Azimuth jog: %s\n", (char *)pgsub->b);
    terminator = drvPmacMbxWriteRead(0, pgsub->b, response, errmsg);
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->b, errmsg);
      ret = 1;
    }
  }

  if( !ret )  /* Send the Elevation Jog */
  {
    printf("SendJog: Sending Elevation jog: %s\n", (char *)pgsub->c);
    terminator = drvPmacMbxWriteRead(1, pgsub->c, response, errmsg);
    if( errmsg[0] )
    {
      printf("PMAC command = %s,  Error: %s\n", (char *)pgsub->c, errmsg);
      ret = 1;
    }
  }

  *(long *)pgsub->vala = 1;  /* Set Slew state to TRUE */

  return(ret);
}


long endSlew( struct genSubRecord *pgsub )
{
  long debug;

  debug   = *(long *)pgsub->a;

  if( debug )
    printf("endDatumS: End of Datum command\n");


  *(long *)pgsub->vala = 0; /* Set Slew state to FALSE */

  return(0);
}

/*
 * This routine puts the time stamped positions into an array
 *
 * INPUTS:
 *      pgsub->a = Azimuth Captured Time                        (DOUBLE).
 *      pgsub->b = Azimuth Captured Position (Degrees)          (DOUBLE).
 *      pgsub->c = Azimuth Captured Velocity                    (DOUBLE).
 *      pgsub->d = Elevation Captured Time                      (DOUBLE).
 *      pgsub->e = Elevation Captured Position (Degrees)        (DOUBLE).
 *      pgsub->j = Elevation Captured Velocity                  (DOUBLE).
 *
 * OUTPUTS:
 *      pgsub->vala = 6 elements array containning:
 *                    Azimtuh TimeStamp                         (DOUBLE).
 *                    Azimuth Position                          (DOUBLE).
 *                    Azimuth Velocity                          (DOUBLE).
 *                    Elevation TimeStamp                       (DOUBLE).
 *                    Elevation Position                        (DOUBLE).
 *                    Elevation Velocity                        (DOUBLE).
 */

long timeStamp( struct genSubRecord *pgsub )
{
  static double timeStampArray[6];

  timeStampArray[0] = *(double *)pgsub->a;
  timeStampArray[1] = *(double *)pgsub->b;
  timeStampArray[2] = *(double *)pgsub->c;
  timeStampArray[3] = *(double *)pgsub->d;
  timeStampArray[4] = *(double *)pgsub->e;
  timeStampArray[5] = *(double *)pgsub->j;

  memcpy( pgsub->vala, timeStampArray, 6*sizeof(double) );

  return(0);
}

long trajLog (struct genSubRecord *pgsub)
{
    long   follow;
   
    follow          = *(long *)pgsub->i;
   
    if( (logTrajFlag) && (follow) )
    {

        logAxisTraj[logDisCounter].azDemandPos     = *(double *)pgsub->a;
        logAxisTraj[logDisCounter].azPmacDemandPos = *(double *)pgsub->b;
        logAxisTraj[logDisCounter].azCurrentPos    = *(double *)pgsub->c;
        logAxisTraj[logDisCounter].azCurrentVel    = *(double *)pgsub->d;
        logAxisTraj[logDisCounter].elDemandPos     = *(double *)pgsub->e;
        logAxisTraj[logDisCounter].elPmacDemandPos = *(double *)pgsub->f;
        logAxisTraj[logDisCounter].elCurrentPos    = *(double *)pgsub->g;
        logAxisTraj[logDisCounter].elCurrentVel    = *(double *)pgsub->h;
        logDisCounter = logDisCounter + 1;
        logDisCounter %= 10000;

    }

    return(0);
}

void dumpTraj()
{
    int         i;
    FILE        *fp;

    if ((fp    = fopen ("logTrajData.dat", "w")) == NULL) {
        printf ("Cannot open logTrajData file\n");
        return;
    }

    /* Print values starting from the minimum value.
     */

    fprintf (fp, "MCSazDemandPos azPmacDemandPos azCurrentPos azCurrentVel ");
    fprintf (fp, "MCSelDemandPos elPmacDemandPos elCurrentPos elCurrentVel\n");

    for (i = 0;  i < 10000; i++)
    {   i %= 10000;
        fprintf (fp, "%.8f ", logAxisTraj[i].azDemandPos);
        fprintf (fp, "%.8f ", logAxisTraj[i].azPmacDemandPos);
        fprintf (fp, "%.8f ", logAxisTraj[i].azCurrentPos);
        fprintf (fp, "%.8f ", logAxisTraj[i].azCurrentVel);
        fprintf (fp, "%.8f ", logAxisTraj[i].elDemandPos);
        fprintf (fp, "%.8f ", logAxisTraj[i].elPmacDemandPos);
        fprintf (fp, "%.8f ", logAxisTraj[i].elCurrentPos);
        fprintf (fp, "%.8f\n", logAxisTraj[i].elCurrentVel);

    }
    fclose (fp);


}

void logTrajClean()
{
    int i;
    for (i = 0;  i < 10000; i++)
    {
         logAxisTraj[i].azDemandPos     = 0.0;
         logAxisTraj[i].azPmacDemandPos = 0.0;
         logAxisTraj[i].azCurrentPos    = 0.0;
         logAxisTraj[i].azCurrentVel    = 0.0;
         logAxisTraj[i].elDemandPos     = 0.0;
         logAxisTraj[i].elPmacDemandPos = 0.0;
         logAxisTraj[i].elCurrentPos    = 0.0;
         logAxisTraj[i].elCurrentVel    = 0.0;
    }
}

void logTrajDisable()
{
    logTrajFlag    = 0;
    printf ("Trajectory logging disable\n");

}

void logTrajEnable()
{
    logDisCounter = 0;
    logTrajFlag    = 1;
    printf ("Trajectory logging enable\n");

}

long log_console (struct genSubRecord *pgsub)
{
    printf("Command received: %s\n", (char *)pgsub->a);
    return(0);
} 
epicsRegisterFunction(handPaddleStop);
epicsRegisterFunction(log_console);
epicsRegisterFunction(setMask);
epicsRegisterFunction(delayStart);
epicsRegisterFunction(delayReset);
epicsRegisterFunction(SendJog);
epicsRegisterFunction(setErrorString);
epicsRegisterFunction(torqueCalc);
epicsRegisterFunction(pwdCommand);
epicsRegisterFunction(nullSub);
epicsRegisterFunction(GISdebugInit);
epicsRegisterFunction(endMove);
epicsRegisterFunction(setErrorString1);
epicsRegisterFunction(GISdebug);
epicsRegisterFunction(rebootSub);
epicsRegisterFunction(speedControl);
epicsRegisterFunction(timeStamp);
epicsRegisterFunction(trajLog);
epicsRegisterFunction(vecntsTodeg);
