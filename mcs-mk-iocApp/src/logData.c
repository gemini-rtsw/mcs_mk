#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsPrint.h>
#include <epicsTimer.h>
#include <epicsTime.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <genSubRecord.h>
#include <menuCarstates.h>
#include <caLogDataDriver.h>
#include <mcssir.h>
#include <mcs.h>
#include <drvPmacGat.h>
#include <sys/stat.h>

#define TWO_POWER_24    16777216
#define MAX_FILE_LINES  100000



char *decTohex( int, int, int, int );

/* 
 * Creates lower 3 Hex digits of "Data Gathering Selection Mask".
 * PMAC variable I20.
 *
 * INPUTS:
 * 	pgsub->a = YES/NO       (STRING).
 * 	pgsub->b = YES/NO       (STRING).
 * 	pgsub->c = YES/NO       (STRING).
 * 	pgsub->d = YES/NO       (STRING).
 * 	pgsub->e = YES/NO       (STRING).
 * 	pgsub->f = YES/NO       (STRING).
 * 	pgsub->g = YES/NO       (STRING).
 * 	pgsub->h = YES/NO       (STRING).
 * 	pgsub->i = YES/NO       (STRING).
 * 	pgsub->j = YES/NO       (STRING).
 * 	pgsub->k = YES/NO       (STRING).
 *
 * OUTPUTS:
 * 	pgsub->vala = First 3 Hex characters of mask  (STRING).
 *
 */

long configMaskA( struct genSubRecord *pgsub )
{
  int v0;
  int v1;
  int v2;
  int v3;

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;

  /* Clean mask */

  strcpy(pgsub->vala, (char *)decTohex(v3, v2, v1, v0));

  if( !strcmp(pgsub->h, "YES") )
    v0 = 1; 
  if( !strcmp(pgsub->i, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->j, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->k, "YES") )
    v3 = 1; 
  /*printf("mask1 = %i %i %i %i\n", v3,v2,v1,v0); */
  strcpy(pgsub->vala, (char *)decTohex(v3, v2, v1, v0));
  
  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  if( !strcmp(pgsub->d, "YES") )
    v0 = 1; 
  if( !strcmp(pgsub->e, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->f, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->g, "YES") )
    v3 = 1; 
  /*printf("mask2 = %i %i %i %i\n", v3,v2,v1,v0); */
  strcat(pgsub->vala, (char *)decTohex(v3, v2, v1, v0));

  /*
     Note we always log the servo counter, so "switch 1" is
     always "YES". This is not user configurable.
  */

  v0 = 1;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  if( !strcmp(pgsub->a, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->b, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->c, "YES") )
    v3 = 1; 
  /*printf("mask3 = %i %i %i %i\n", v3,v2,v1,v0); */
  strcat(pgsub->vala, (char *)decTohex(v3, v2, v1, v0));

  return(0);
}


/* 
 * Creates upper 3 Hex digits and final 6 digit 
 * "Data Gathering Selection Mask".
 * PMAC variable I20.
 *
 * INPUTS:
 * 	pgsub->a = Lower 3 Hex digits  (STRING).
 * 	pgsub->b = YES/NO              (STRING).
 * 	pgsub->c = YES/NO              (STRING).
 * 	pgsub->d = YES/NO              (STRING).
 * 	pgsub->e = YES/NO              (STRING).
 * 	pgsub->f = YES/NO              (STRING).
 * 	pgsub->g = YES/NO              (STRING).
 * 	pgsub->h = YES/NO              (STRING).
 * 	pgsub->i = YES/NO              (STRING).
 * 	pgsub->j = YES/NO              (STRING).
 * 	pgsub->k = YES/NO              (STRING).
 * 	pgsub->l = YES/NO              (STRING).
 * 	pgsub->m = YES/NO              (STRING).
 *
 * OUTPUTS:
 * 	pgsub->vala = Command string which sets I20  (STRING).
 * 	pgsub->valb = Command string which sets I19  (STRING).
 * 	pgsub->valc = Command string which sets I45  (STRING).
 *
 */

long configMaskB( struct genSubRecord *pgsub )
{
  int  v0;
  int  v1;
  int  v2;
  int  v3;
  char buf[8];

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  /* Clean mask */

  strcpy(pgsub->vala, (char *)decTohex(v3, v2, v1, v0));

  if( !strcmp(pgsub->j, "YES") )
    v0 = 1; 
  if( !strcmp(pgsub->k, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->l, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->m, "YES") )
    v3 = 1; 
  /*printf("mask1b = %i %i %i %i\n", v3,v2,v1,v0); */
  strcpy(buf, (char *)decTohex(v3, v2, v1, v0));

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  if( !strcmp(pgsub->f, "YES") )
    v0 = 1; 
  if( !strcmp(pgsub->g, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->h, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->i, "YES") )
    v3 = 1; 
  /*printf("mask2b = %i %i %i %i\n", v3,v2,v1,v0); */
  strcat(buf, (char *)decTohex(v3, v2, v1, v0));

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  if( !strcmp(pgsub->b, "YES") )
    v0 = 1; 
  if( !strcmp(pgsub->c, "YES") )
    v1 = 1; 
  if( !strcmp(pgsub->d, "YES") )
    v2 = 1; 
  if( !strcmp(pgsub->e, "YES") )
    v3 = 1; 
  /*printf("mask3b = %i %i %i %i\n", v3,v2,v1,v0); */
  strcat(buf, (char *)decTohex(v3, v2, v1, v0));

  /* Add on lower 3 Hex digits */
  strcat(buf, pgsub->a);

  /* Now compose command to PMAC */
  sprintf(pgsub->vala, "I20=$%s", buf);

  return(0);
}


/* 
 * Creates the command strings to set the PMAC variables: I22-I44
 * These are the addresses of memory locations to be logged.
 *
 * INPUTS:
 * 	pgsub->a = Description of value to be logged            (STRING).
 * 	pgsub->b = X or Y or D or L or F or P (PMAC data type)  (STRING).
 * 	pgsub->c = PMAC address typed in by user                (STRING).
 * 	pgsub->d = Which address am I?                          (DOUBLE).
 * 	pgsub->e = YES/NO                                       (STRING).
 *
 * OUTPUTS:
 * 	pgsub->vala = PMAC Command which sets I22-44            (STRING).
 */

long configLogAddress( struct genSubRecord *pgsub )
{
  char buf[MAX_STRING_SIZE];
  char str[MAX_STRING_SIZE];
  char desc[MAX_STRING_SIZE];
  char mask[MAX_STRING_SIZE];
  long num;
  long error;

  strcpy(desc,pgsub->a);
  strcpy(mask,pgsub->e);
 
  printf("MASK = %s\n",mask);

  num   = (long)(*(double *)pgsub->d);
  num  += 20;
  error = check_string(pgsub->c, str, MAX_STRING_SIZE, 0);
  if( !error )
  {
    if( !strcmp(pgsub->b, "Y") )
      sprintf(buf, "$00%s", str);
    else if( !strcmp(pgsub->b, "X") )
      sprintf(buf, "$40%s", str);
    else if( !strcmp(pgsub->b, "L") )
      sprintf(buf, "$C0%s", str);
    else if( !strcmp(pgsub->b, "D") )
      sprintf(buf, "$80%s", str);
    else if( !strcmp(pgsub->b, "F") )
      sprintf(buf, "$F0%s", str);
    else if( !strcmp(pgsub->b, "P") )
      sprintf(buf, "$E0%s", str);
    sprintf(pgsub->vala, "I%ld=%s", num, buf);
    printf("I%ld=%s\n", num, buf);
  }
  return(0);
}


long configLogAddressI( struct genSubRecord *pgsub )
{
  strcpy(pgsub->c, "0");
  return(0);
}


/*
 * Writes header information and sends five commands to PMAC and
 * sets status records.
 * 
 * INPUTS:
 *	pgsub->a    = PMAC Logging Frequency            (DOUBLE).
 *      pgsub->b    = Number of cycles at which to log  (LONG).
 *      pgsub->c    = File name                         (STRING).
 *      pgsub->d    = Data ID                           (STRING).
 *      pgsub->e    = Captured Time                     (DOUBLE).
 *      pgsub->f    = Servo Counter Value               (DOUBLE).
 *      pgsub->g    = Card Number                       (DOUBLE).
 *      pgsub->h    = Start Time                        (LONG).
 *      pgsub->i    = End Time                          (LONG).
 *
 * OUTPUTS:
 * 	pgsub->vala = PMAC Command "I19=<n>"            (STRING).
 * 	pgsub->valb = Not Used.                         (STRING).
 * 	pgsub->valc = Not Used.                         (STRING).
 * 	pgsub->vald = Not Used.                         (STRING).
 * 	pgsub->vale = PMAC Command "I9=0"               (STRING).
 * 	pgsub->valf = Set Log state to "MCS_LOG_PRIMED" (LONG).
 * 	pgsub->valg = PMAC Logging Frequency            (DOUBLE).
 * 	pgsub->valh = Start Time                        (LONG).
 * 	pgsub->vali = End Time                          (LONG).
 *
 */

long writeHeader( struct genSubRecord *pgsub )
{
  epicsTimeStamp  now;
  char     nowText[28];
  char     tbuf[28];
  double   freq;
  long     ncycles;
  char     fileName[MAX_STRING_SIZE];
  char     dataID[MAX_STRING_SIZE];
  double   capTime;
  long     startTime;
  long     endTime;
  long     card;
  long     servoCounter;
  char     strCard[3];
  char     header1[2*HEADER_SIZE];
  char     header2[HEADER_SIZE];

  freq         = *(double *)pgsub->a;
  ncycles      = *(long *)pgsub->b;
  strcpy(fileName, pgsub->c);
  strcpy(dataID, pgsub->d);
  capTime      = *(double *)pgsub->e;
  servoCounter = (long)(*(double *)pgsub->f);
  card         = (long)(*(double *)pgsub->g);
  startTime    = *(long *)pgsub->h;
  endTime      = *(long *)pgsub->i;

  /* Get the local time as a time stamp */
  /*tsLocalTime(&now);
  sprintf(tbuf, "%s", tsStampToText(&now, TS_TEXT_MMDDYY, nowText));*/
  epicsTimeGetCurrent(&now);
  sprintf(tbuf, "%s", epicsTimeToStrftime(&now, sizeof(nowText), "%H%M%S%T", nowText));

  /* First header line */
  sprintf(header1, "MCS, Time = %s, LOGDATA, Filename = %s, DataID = %s, Start = %ld, End = %ld\nFrequency = %f, Period = %ld, ServoCounter = %ld, CapTime = %f\n", 
         tbuf, fileName, dataID, startTime, endTime, freq, ncycles, servoCounter, capTime);

  if( card == 0 )
    strcpy(strCard, "az");
  else if( card == 1 )
    strcpy(strCard, "el");
  else if( card == 2 )
    strcpy(strCard, "cw");

  /* Second header line */
  header2[0] = '\0';
  caReadHeader(strCard, header2);

  strcat(header1, header2);

  /* Now initialise the driver and write the header */
  drvPmacGatInit( card, strCard, fileName, header1);

  sprintf(pgsub->vala, "I19=%ld", ncycles);
  strcpy(pgsub->valb, " ");
  strcpy(pgsub->valc, " ");
  strcpy(pgsub->vald, " ");
  strcpy(pgsub->vale, "I9=0");
  *(long *)pgsub->valf   = MCS_LOG_PRIMED;
  *(double *)pgsub->valg = freq;
  *(long *)pgsub->valh   = startTime;
  *(long *)pgsub->vali   = endTime;

  return(0);
}


/*
 * Starts the PMAC device driver logging.
 * 
 * INPUTS:
 *	pgsub->a    = Card Number                       (DOUBLE).
 *	pgsub->b    = Size of in-memory buffer (Mbytes) (DOUBLE).
 *
 * OUTPUTS:
 * 	pgsub->vala = Set Log state to "MCS_LOG_ON"  (LONG).
 * 	pgsub->valb = Set logData CAR record to BUSY (LONG).
 *
 */

long startDriver( struct genSubRecord *pgsub )
{
  long   card;
  double size;

  *(long *)pgsub->vala = MCS_LOG_ON;
  *(long *)pgsub->valb = menuCarstatesBUSY;
  card                 = (long)(*(double *)pgsub->a);
  size                 = *(double *)pgsub->b * 1024 * 1024;

  drvPmacGatStart( card, (long)size );

  return(0);
}


/*
 * Stops the PMAC device driver logging.
 * 
 * INPUTS:
 *	pgsub->a    = Card Number   (DOUBLE).
 *
 * OUTPUTS:
 * 	pgsub->vala = Set Log state to "MCS_LOG_OFF" (LONG).
 * 	pgsub->valb = Set logData CAR record to IDLE (LONG).
 *
 */

long stopDriver( struct genSubRecord *pgsub )
{
  *(long *)pgsub->vala = MCS_LOG_OFF;
  *(long *)pgsub->valb = menuCarstatesIDLE;

  drvPmacGatStop( (long)(*(double *)pgsub->a) );

  return(0);
}


/*
 * Gets the latest PMAC logging error string.
 * 
 * INPUTS:
 *      pgsub->a    = PMAC card number               (DOUBLE).
 *
 * OUTPUTS:
 * 	pgsub->vala = Error string                   (STRING).
 * 	pgsub->valb = Trigger value for Wait record  (DOUBLE).
 * 	pgsub->valc = Was there an error?            (DOUBLE).
 *
 */

long errorReport1( struct genSubRecord *pgsub )
{
  char err[MAX_STRING_SIZE];
  char *ptr;
  long card;

  card = (long)(*(double *)pgsub->a);

  *(double *)pgsub->valb = 1.0;

  drvPmacGatError( card, err );

  if( err[0] == '\0' )
  {
    ptr    = pgsub->vala;
    ptr[0] = '\0';
    *(double *)pgsub->valc = 0;
  }
  else
  {
    strcpy(pgsub->vala, err);
    *(double *)pgsub->valc = 1;
    drvPmacGatResetError( card );
  }

  return(0);
}


/*
 * Reports the Error to logData CAR and SIR records
 * and stops the driver.
 * 
 * INPUTS:
 *      pgsub->a = Error string                     (STRING).
 *
 * OUTPUTS:
 * 	pgsub->vala = Set SIR status to MCS_LOG_OFF (LONG).
 * 	pgsub->valb = Error string                  (STRING).
 * 	pgsub->valc = Set CAR status to menuCarstatesERROR.  (LONG).
 * 	pgsub->vald = Process CLEAR Fanout for Az.  (LONG).
 * 	pgsub->vale = Process CLEAR Fanout for El.  (LONG).
 * 	pgsub->valf = Process CLEAR Fanout for Cw.  (LONG).
 *
 *      vald, vale, valf ensure that timers are cleared if an error occurs.
 *
 */

long errorReport2( struct genSubRecord *pgsub )
{
  *(long *)pgsub->vala = MCS_LOG_OFF;
  strcpy(pgsub->valb, pgsub->a);
  *(long *)pgsub->valc = menuCarstatesERROR;
  *(long *)pgsub->vald = 1;
  *(long *)pgsub->vale = 1;
  *(long *)pgsub->valf = 1;

  /* Switch off the driver for all PMAC's */

  drvPmacGatStop(0);
  drvPmacGatStop(1);
  // drvPmacGatStop(2);

  return(0);
}


/*
 * Gets the write file flag and current LAN transfer rate.
 * 
 * INPUTS:
 *      pgsub->a    = PMAC card number      (DOUBLE).
 *
 * OUTPUTS:
 * 	pgsub->vala = Write Flag            (LONG).
 * 	pgsub->valb = Transfer Rate (kb/s)  (DOUBLE).
 *
 */

long writeMonitor( struct genSubRecord *pgsub )
{
  long card;
  int  error;

  card = (long)(*(double *)pgsub->a);

  error = drvPmacGatWriteMonitor( card, (long *)pgsub->vala, (double *)pgsub->valb );

  return(0);
}


long _pmacRamGetY( char *buf, long *val )
{
  short ram0;
  short ram1;
  long  val0;

  ram0 = (buf[0]<<8) + (buf[1] & 0xFF);
  ram1 = (buf[2]<<8) + (buf[3] & 0xFF);

/*
  printf("ram0 = 0x%x  ram1 = 0x%x  ", ram0, ram1);
*/

  val0 = ((0x000000ff & (long) ram1) << 16) | (0x0000ffff & (long) ram0);

  *val = val0;

  return(0);
}

long _pmacRamGetL( char *buf, double *pVal )
{
  short    ram0;
  short    ram1;
  short    ram2;
  short    ram3;
  long     val0;
  long     val1;
  double   mantissa = 0.0;
  long int exponent = 0;
  double   valD;

  ram0 = (buf[0]<<8) + (buf[1] & 0xFF);
  ram1 = buf[3];
  ram2 = (buf[4]<<8) + (buf[5] & 0xFF);
  ram3 = buf[7];

/*
  printf("ram0 = 0x%x, ram1 = 0x%x, ram2 = 0x%x, ram3 = 0x%x  ",
          ram0, ram1, ram2, ram3);
*/

  /* Convert 48 bit floating point format */

  val0     = (((long) ram1) << 16) | (0x0000ffff & (long) ram0);
  val1     = (((long) ram3) << 16) | (0x0000ffff & (long) ram2);
  mantissa = ((double) val1) * 4096.0 + (double) ((val0 >> 12) & 0x00000fff);
  exponent = (val0 & 0x00000fff) - 2082;  /* 0x7ff + 35 */

  if(mantissa == 0.0)
    valD = 0.0;
  else
    valD = mantissa * pow(2.0, (double) exponent);

  /* Return value */

  *pVal = valD;

  return(0);
}


long _pmacRamGetD( char *buf,  double *pVal )
{
  short  ram0;
  short  ram1;
  short  ram2;
  short  ram3;
  long   val0;
  long   val1;
  double valD;

  ram0 = (buf[0]<<8) + (buf[1] & 0xFF);
  ram1 = buf[3];
  ram2 = (buf[4]<<8) + (buf[5] & 0xFF);
  ram3 = buf[7];

/*
  printf("ram0 = 0x%x, ram1 = 0x%x, ram2 = 0x%x, ram3 = 0x%x\n",
          ram0, ram1, ram2, ram3);
*/

  /* Convert 48 bit fixed-point format */

  val0 = ((0x000000ff & (long) ram1) << 16) | (0x0000ffff & (long) ram0);
  val1 =              (((long) ram3) << 16) | (0x0000ffff & (long) ram2);
  valD = (double) val1 * 16777216.0 + (double) val0;

  *pVal = valD;

  return(0);
}


long _pmacRamGetF( char *buf, double *pVal )
{
  short  ram0;
  short  ram1;
  double valD;
  union
  {
    long  val0;
    float valF;
  }valU;

  ram0 = (buf[0]<<8) + (buf[1] & 0xFF);
  ram1 = (buf[4]<<8) + (buf[5] & 0xFF);

 printf("en _pmacRamGetF !!!!! \n");

  printf("_pmacRamGetF: ram0 = 0x%x, buf[0] = 0x%x, buf[1] = 0x%x, buf[2] = 0x%x, buf[3] = 0x%x, buf[4] = 0x%x, buf[5] = 0x%x, buf[6] = 0x%x, buf[7] = 0x%x\n", ram0, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);


  /* Convert 32 bit floating point format */
  valU.val0 = (((long)ram1) << 16) | (0x0000ffff & (long)ram0);
  valD      = (double) valU.valF;

  /* Return value */
  *pVal = valD;

  return(0);
}

long _pmacRamGetP( char *buf, long *pVal )
{
  short ram0;
  short ram1;
  long  val0;

  /* Read PMAC DPRAM */

  ram0 = (buf[0]<<8) + (buf[1] & 0xFF);
  ram1 = (buf[4]<<8) + (buf[5] & 0xFF);

/*
  printf("_pmacRamGetP: buf[0] = 0x%x, buf[1] = 0x%x, buf[2] = 0x%x, buf[3] = 0x%x, buf[4] = 0x%x, buf[5] = 0x%x, buf[6] = 0
x%x, buf[7] = 0x%x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
  printf("_pmacRamGetP: ram0 = 0x%x, ram1 = 0x%x\n", ram0, ram1);
*/

  /* Convert 32 bit fixed-point format */
  val0 = (((long) ram1) << 16) | (0x0000ffff & (long) ram0);

  /* Return value */
  *pVal = val0;

  return (0);
}

/*  This routine translate the PMAC logs into a text file.
 *
 *
 *  INPUTS:
 *      psub->a = File name    (STRING).
 *      psub->b = Card number  (STRING).
 *
 *  OUTPUTS:
 *
 */


long translate(struct genSubRecord *pgsub)
{
  char   fname[32];
  char   fnameout[32];
  char   line1[1024];
  char   line2[1024];
  FILE   *fd;
  FILE   *fdout;
  char   *buf;
  char   *str;
  double capTime;
  double freq;
  double tai;
  long   counter;
  long   numSrc;
  long   period;
  int    i;
  int    first;
  int    wrapFactor;
  int    multiFiles;
  long   tot;
  long   lineSize;
  long   yval;
  long   oldsc;
  long   wrapsc;
  long   filenum;
  long   numlines;
  int    size;
  double lval;
  double dval;
  char   srcType[25];
  struct stat stbuf;
  long   card;

  strcpy(fname, pgsub->a);
  strcpy(fnameout, fname);
  card = (long)(*(double *)pgsub->b);
  
  printf("In translate \n");

  multiFiles = 0;
  
  if ( card == 0)
  {
      sprintf(fname, "%saz.raw", fname);
      sprintf(fnameout,"%saz", fnameout);
  }
  else if (card == 1)
  {
      sprintf(fname, "%sel.raw", fname);
      sprintf(fnameout,"%sel", fnameout);
  }
  else if (card == 2)
  {
      sprintf(fname, "%scw.raw", fname);
      sprintf(fnameout,"%scw", fnameout);
  }

  if( stat(fname, &stbuf) == -1 )
  {
    printf("Cannot get file size (card %ld)\n",card);
    return(0);
  }
  size = stbuf.st_size;

  fd = fopen(fname, "r");
  if( fd )
  {
    /* Read header lines */

    fgets(line1, 1024, fd);
    fscanf(fd, "Frequency = %lf, Period = %ld, ServoCounter = %ld, CapTime = %lf", 
           &freq, &period, &counter, &capTime);
    fscanf(fd, "%ld", &numSrc);
    fgets(line2, 1024, fd);

    filenum = 1;
    sprintf(fnameout, "%s%03ld.dat", fnameout, filenum);
    fdout = fopen(fnameout, "w+");

    str        = (char *)strtok(line2, ":");
    srcType[0] = 'X';
    srcType[1] = str[strlen(str)-1];
    i          = 2;
    while( str )
    {
      str = (char *)strtok(NULL, ":");
      if( str )
        srcType[i++] = str[strlen(str)-1];
    }
    srcType[i] = '\0';

    i        = 0;
    lineSize = 0;
    while( srcType[i] != '\0' )
    {
      switch(srcType[i++])
      {
        case 'X':
          lineSize += 4;
          break;

        case 'Y':
          lineSize += 4;
          break;

        case 'L':
          lineSize += 8;
          break;

        case 'D':
          lineSize += 8;
          break;

        case 'F':
          lineSize += 8;
          break;

        case 'P':
          lineSize += 8;
          break;

        default:
          break;
      }
    }
    buf = malloc(lineSize);

    oldsc      = 0;
    wrapsc     = 0;
    numlines   = 0;
    first      = 1;
    wrapFactor = 0;
    while( fread( buf, 1, lineSize, fd ) )
    {
      if( multiFiles )
      {
        numlines %= MAX_FILE_LINES;
        if( !numlines )
        {
          if( first )
            first = 0;
          else
          {
            fclose(fdout);
            filenum++;
            sprintf(fnameout, "%s%03ld.dat", fnameout, filenum);
            fdout = fopen(fnameout, "w+");
          }
        }
        numlines++;
      }

      tot = 0;
      for(i=0; i<numSrc; i++)
      {
        if( srcType[i] == 'X' )
        {
          _pmacRamGetY( buf+tot, &yval );
          if(i==0)
          {
            /* Check for wrap around */
            if( yval < wrapsc )
            {
              wrapFactor++;
              printf("Servo Counter wrapped %d times: oldSC = %ld, newSC = %ld\n", wrapFactor, wrapsc, yval);
            }
            wrapsc = yval;
            yval  += (wrapFactor*TWO_POWER_24);

            tai = capTime + (yval-counter)/((double)period*freq);
            if( oldsc && ((oldsc+period) != yval) )
            {
              fprintf(fdout, " ERROR ");
              printf("Missing Data at Servo Counter: %ld, File: %s\n", yval, fnameout);
              fprintf(fdout, "%ld    ", yval);
              fclose(fd);
              fclose(fdout);

              return(0);
            } 
            oldsc = yval;
            fprintf(fdout, "%ld    ", yval);
          }
          else
            fprintf(fdout, "%ld    ", yval);
          tot += 4;
        }
        else if( srcType[i] == 'Y' )
        {
          _pmacRamGetY( buf+tot, &yval );
          fprintf(fdout, "%ld    ", yval);
          tot += 4;
        }
        else if( srcType[i] == 'L' )
        {
          _pmacRamGetL( buf+tot, &lval );
          fprintf(fdout, "%f    ", lval);
          tot += 8;
        }
        else if( srcType[i] == 'D' )
        {
          _pmacRamGetD( buf+tot, &dval );
          fprintf(fdout, "%f    ", dval);
          tot += 8;
        }
        else if( srcType[i] == 'F' )
        {
          _pmacRamGetF( buf+tot, &dval );
          fprintf(fdout, "%f    ", dval);
          tot += 8;
        }
        else if( srcType[i] == 'P' )
        {
          _pmacRamGetP( buf+tot, &yval );
          fprintf(fdout, "%ld    ", yval);
          tot += 8;
        }
        else
          printf("Should never see this!\n");
      }
      fprintf(fdout, "\n");
    }
    printf("i = %i\n",i);
    fclose(fd); 
  }
  else
    printf("Error opening file: %s\n", fname);

  return(0);
}

epicsRegisterFunction(translate);
epicsRegisterFunction(stopDriver);
epicsRegisterFunction(startDriver);
epicsRegisterFunction(errorReport1);
epicsRegisterFunction(errorReport2);
epicsRegisterFunction(writeHeader);
epicsRegisterFunction(configLogAddress);
epicsRegisterFunction(configMaskA);
epicsRegisterFunction(configMaskB);
epicsRegisterFunction(configLogAddressI);
