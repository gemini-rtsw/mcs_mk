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
#include <subRecord.h>
#include <genSubRecord.h>
#include <mcssir.h>
#include <mcscad.h>
#include <mcs.h>
#include <drvPmac.h>
#include <timeLib.h>

#define TWO_POWER_24  16777216

/* This routine runs at iocInit and reads the PMAC variables I208 and
 * I209.
 *
 * Used to communicate variables with "SetStatus" routine.
 * pgsub->o = I208  (LONG)
 * pgsub->p = I209  (LONG)
 *
 * INPUTS:
 *	pgsub->q = Card Number (DOUBLE).  (Constant hardware inputs have to be doubles).
 *
 */

long initSetPositions( struct genSubRecord *pgsub )
{
  long I208;
  long I209;
  long card;
  long terminator;
  char command[MAX_STRING_SIZE];
  char response[MAX_STRING_SIZE];
  char errmsg[MAX_STRING_SIZE];

  card = (long)(*(double *)pgsub->q);

  sprintf(command, "I208");
  terminator = drvPmacMbxWriteRead(card, command, response, errmsg);
  sscanf(response, "%ld", &I208);
  *(long *)pgsub->o = I208;

  sprintf(command, "I209");
  terminator = drvPmacMbxWriteRead(card, command, response, errmsg);
  sscanf(response, "%ld", &I209);
  *(long *)pgsub->p = I209;

  return(0);
}


/*
 * This routine runs from a 10Hz scan.
 * It is responsible for setting, amongst other
 * things, the current position, position error, current velocity, 
 * velocity error and axis state.
 * 
 * INPUTS:
 *	pgsub->a = Demand Position (degrees)			              (DOUBLE).
 *	pgsub->b = Demand Velocity (degrees/second)		              (DOUBLE).
 *	pgsub->c = ECT*I208*PMAC Demand Position (counts)                     (DOUBLE).
 *	pgsub->d = ECT*I208*Current Position (counts)	                      (DOUBLE).
 *	pgsub->e = (ECT*I208*PMAC Demand Velocity)/3 (counts/millisecond)     (DOUBLE).
 *      pgsub->f = ECT*I209*Current Velocity (counts per servo cycle)         (DOUBLE).
 *      pgsub->g = Servo Frequency (Hz)                                       (DOUBLE).
 *      pgsub->h = Counts per degree				              (DOUBLE).
 *      pgsub->i = Following Error				              (DOUBLE).
 *      pgsub->o = I208                                                       (LONG).
 *      pgsub->p = I209                                                       (LONG).
 *	pgsub->q = Card Number						      (DOUBLE).
 *
 *
 * OUTPUTS:
 *	pgsub->vala = Current Position (degrees)		(DOUBLE).
 *	pgsub->valb = Current Position Error (degrees)		(DOUBLE).
 *	pgsub->valc = PMAC Demand Position (degrees)		(DOUBLE).
 *	pgsub->vald = PMAC Following Error (degrees)		(DOUBLE).
 *	pgsub->vale = Current Velocity (degrees/second)		(DOUBLE).
 *	pgsub->valf = Current Velocity Error (degrees/second)	(DOUBLE).
 */

long SetPositions( struct genSubRecord *pgsub )
{
  double mcsDemandPosD;
  double mcsPosErrorD = 0.0;
  double mcsVelErrorD = 0.0;
  double pmacDemandPosC;
  double pmacDemandPosD = 0.0;
  double pmacFollowErrorC;
  double pmacFollowErrorD = 0.0;
  double currentPosC;
  double currentPosD = 0.0;
  double currentVelC;
  double currentVelD = 0.0;
  double pmacDemandVelC = 0.0;
  double pmacDemandVelD = 0.0;
  double servoFreq;
  double countsPerDegree;
  long   I208;
  long   I209;

  mcsDemandPosD    = *(double *)pgsub->a;
  pmacDemandPosC   = *(double *)pgsub->c;
  currentPosC      = *(double *)pgsub->d;
  pmacDemandVelC   = *(double *)pgsub->e;
  currentVelC      = *(double *)pgsub->f;
  servoFreq        = *(double *)pgsub->g;
  countsPerDegree  = *(double *)pgsub->h;
  pmacFollowErrorC = *(double *)pgsub->i;
  I208             = *(long *)pgsub->o;
  I209             = *(long *)pgsub->p;
 
  if ( (countsPerDegree != 0.0)  && (I208 != 0.0))
  { 
     currentPosD      = currentPosC/(I208*countsPerDegree);
     pmacFollowErrorD = pmacFollowErrorC/(I208*countsPerDegree);
     pmacDemandPosD   = pmacDemandPosC/(I208*countsPerDegree);
  }

  if ( (countsPerDegree != 0.0)  && (I209 != 0.0) && (servoFreq != 0.0) && (RAW_PER_VE != 0.0) )
  {
     currentVelD      = (currentVelC/(I209*countsPerDegree))*servoFreq*RAW_PER_VE;
     pmacDemandVelD   = (pmacDemandVelC/(I209*countsPerDegree))*servoFreq*RAW_PER_VE;
  }

  mcsPosErrorD = mcsDemandPosD - currentPosD;
  mcsVelErrorD = pmacDemandVelD - currentVelD;

  *(double *)pgsub->vala = currentPosD;
  *(double *)pgsub->valb = mcsPosErrorD;
  *(double *)pgsub->valc = pmacDemandPosD;
  *(double *)pgsub->vald = pmacFollowErrorD;
  *(double *)pgsub->vale = currentVelD;
  *(double *)pgsub->valf = mcsVelErrorD;

  return(0);
}


/*
 * This routine performs the "in-position" calculation at 5 Hz.
 * AWE: Rewriting the inPosition calculation to be solely based on PMAC position errors .. see REL-873 for details
 *      Adding a velocity dependent term .. the PMAC position error remains very low during the first 10 seconds of acceleration
 *
 * INPUTS:
 *	pgsub->a = Azimuth Position Error (Degrees)		(DOUBLE).
 *	pgsub->b = Elevation Position Error (Degrees)		(DOUBLE).
 *	pgsub->c = Follow Flag                          	(DOUBLE).
 *	pgsub->d = Elevation PMAC Position Error (Degrees)	(DOUBLE).
 *	pgsub->e = Position Tolerance (Degrees)			(DOUBLE).
 *	pgsub->f = Velocity Tolerance (Degrees/second)		(DOUBLE).
 *	pgsub->g = Azimuth PMAC Position Error (Degrees)	(DOUBLE).
 *	pgsub->h = PMAC Servo Tolerance (Degrees)       	(DOUBLE).
 *	pgsub->i = Azimuth Current Velocity (Degrees/second)	(DOUBLE).
 *	pgsub->j = Elevation Current Velocity (Degrees/second)	(DOUBLE).

 *
 * OUTPUTS:
 *	pgsub->vala = Whether Azimuth is in-position or not	  (LONG).
 *			MCS_FALSE
 *			MCS_TRUE
 *	pgsub->valb = Whether Elevation is in-position or not	  (LONG).
 *			MCS_FALSE
 *			MCS_TRUE
 *      pgsub->valc = Whether both axes are in-position or not    (LONG).
 *			MCS_FALSE
 *			MCS_TRUE
 *      pgsub->vald = Mask for setting Az. and El. CAR's to IDLE  (LONG).
 *                      0 - Set Nothing
 *                      1 - Set Azimuth
 *                      2 - Set Elevation
 *                      3 - Set Both
 */

long inPositionCalc( struct genSubRecord *pgsub )
{
  double azPosError;
  double elPosError;
  double azPmacPosError;
  double elPmacPosError;
  double PosTolerance;
  double VelTolerance;
  double pmacServoTol;
  double azCurrentVel;
  double elCurrentVel;
  long   following;
  long   mask;

  azPosError      = *(double *)pgsub->a;
  elPosError      = *(double *)pgsub->b;
  following       = (long)(*(double *)pgsub->c);
  PosTolerance    = *(double *)pgsub->e;
  VelTolerance    = *(double *)pgsub->f;
  azPmacPosError  = *(double *)pgsub->g;
  elPmacPosError  = *(double *)pgsub->d;
  pmacServoTol    = *(double *)pgsub->h;
  azCurrentVel    = *(double *)pgsub->i;
  elCurrentVel    = *(double *)pgsub->j;
  mask            = 0;

  if ((fabs(azPmacPosError) < pmacServoTol ) && (fabs(azCurrentVel) < VelTolerance ))
  {
    *(long *)pgsub->vala = MCS_TRUE;
    if( following )
      mask = mask | 1;
  }
  else
    *(long *)pgsub->vala = MCS_FALSE;

  if ((fabs(elPmacPosError) < pmacServoTol ) && (fabs(elCurrentVel) < VelTolerance ))
  {
    *(long *)pgsub->valb = MCS_TRUE;
    if( following )
      mask = mask | 2;
  }
  else
    *(long *)pgsub->valb = MCS_FALSE;

  if( (*(long *)pgsub->vala == MCS_TRUE) && (*(long *)pgsub->valb == MCS_TRUE) )
    *(long *)pgsub->valc = MCS_TRUE;
  else
    *(long *)pgsub->valc = MCS_FALSE;

  *(long *)pgsub->vald = mask;

  return(0);
}


long setAxisState( struct genSubRecord *pgsub )
{
  long dvz;
  long olm;
  long tracking;
  long de;
  long dc;
  long pdc;
  long counter;
  long card;
  long reset = 1;

  dvz      = *(long *)pgsub->a;
  olm      = *(long *)pgsub->b;
  tracking = *(long *)pgsub->c;
  dc       = *(long *)pgsub->d;
  de       = *(long *)pgsub->e;
  pdc      = *(long *)pgsub->f;
  counter  = *(long *)pgsub->g;
  card     = (long)(*(double *)pgsub->h);

/*
  if( card == 0 )
    printf("de = %d, dc = %d, pdc = %d, counter = %d\n", de, dc, pdc, counter);
*/

  if( de == 1 )
  {
    counter = 0;
    if( dc == 1 )
      *(long *)pgsub->vala = MCS_BRAKED;
    else if( dc == 2 )
      *(long *)pgsub->vala = MCS_APPLY_BRAKES;
    else
    ;
/*      printf("setAxisState: Unknown Drive Condition signal - %ld\n", dc); */
  }
  else
  {
    if( dc == 1 )
    {
      if( pdc == 1 )
      {
        counter++;
        if( counter < 24 )
          *(long *)pgsub->vala = MCS_RELEASE_BRAKES;
        else
          *(long *)pgsub->vala = MCS_INTERLOCK;
      }
      else if( pdc == 2 )
      {
        reset = 0;
        *(long *)pgsub->vala = MCS_INTERLOCK;
      }
      else
        ;
        /*printf("setAxisState: Unknown Drive Condition signal - %ld\n", pdc);*/
    }
    else if( dc == 2 )
    {
      counter = 0;
      if( tracking )
        *(long *)pgsub->vala = MCS_TRACKING;
      else if( !olm && !dvz )
        *(long *)pgsub->vala = MCS_SLEWING;
      else
        *(long *)pgsub->vala = MCS_STATIONARY;
    }
    else
      ;
      /*printf("setAxisState: Unknown Drive Condition signal - %ld\n", dc); */
  }

  if( reset )
    *(long *)pgsub->f = dc;
  *(long *)pgsub->g = counter;

  return(0);
}


long engToDeg( struct genSubRecord *pgsub )
{
  double ve;
  double fde;
  double th1;
  double th2;
  double th3;
  double th4;
  double countsPerDeg;

  ve           = *(double *)pgsub->a;
  fde          = *(double *)pgsub->b;
  th1          = *(double *)pgsub->c;
  th2          = *(double *)pgsub->d;
  th3          = *(double *)pgsub->e;
  th4          = *(double *)pgsub->f;
  countsPerDeg = *(double *)pgsub->g;
  
  if ( countsPerDeg != 0.0)
  {
     *(double *)pgsub->vala = ve/countsPerDeg;
     *(double *)pgsub->valb = fde/countsPerDeg;
     *(double *)pgsub->valc = th1/countsPerDeg;
     *(double *)pgsub->vald = th2/countsPerDeg;
     *(double *)pgsub->vale = th3/countsPerDeg;
     *(double *)pgsub->valf = th4/countsPerDeg;
  }

  return(0);
}


long capturedPos( struct genSubRecord *pgsub )
{
  double azbaseSC;
  double azservoFreq;
  double azcountsPerDegree;
  double azcapturedSC;
  double azcapturedPosC;
  double azcapturedVelC;
  double elbaseSC;
  double elservoFreq;
  double elcountsPerDegree;
  double elcapturedSC;
  double elcapturedPosC;
  double elcapturedVelC;
  double capturedTime;
  long   I208;
  long   I209;
  double aaa[3]={0.0,0.0,0.0};
  double bbb[3]={0.0,0.0,0.0};
  double azdiffSC;
  double eldiffSC;
  double aztotalVel, eltotalVel;
  int    i;
  static int ii = 0;
  static double azvel[10];
  static double elvel[10];

  double tai;               /* Raw time read direct from timebus */
  double deltaT = (double) 0.0;            /* Raw time - time stamp (secs) */
  char   dtHealth[16];      /* Time stamp health */
  char   dtHealthMess[MAX_STRING_SIZE]; /* Health message */
  double azrawPos = 0;            /* Azimuth Raw captured position */
  double azrawVel = 0;            /* Azimuth Raw captured velocity */ 
  double azrawTime = 0;           /* Azimuth Raw captured time */

  double elrawPos = 0;            /* Elevation Raw captured position */
  double elrawVel = 0;            /* Elevation Raw captured velocity */ 
  double elrawTime = 0;           /* Elevation Raw captured time */
  static double prevCapturedTime;

  strcpy (dtHealth, "GOOD");
  strcpy (dtHealthMess, " ");

  azbaseSC           = *(double *)pgsub->a;
  azservoFreq        = *(double *)pgsub->b;
  azcountsPerDegree  = *(double *)pgsub->c;
  azcapturedSC       = *(double *)pgsub->d;
  azcapturedPosC     = *(double *)pgsub->e;
  azcapturedVelC     = *(double *)pgsub->f;
  elbaseSC           = *(double *)pgsub->h;
  elservoFreq        = *(double *)pgsub->i;
  elcountsPerDegree  = *(double *)pgsub->k;
  elcapturedSC       = *(double *)pgsub->l;
  elcapturedPosC     = *(double *)pgsub->m;
  elcapturedVelC     = *(double *)pgsub->n;
  capturedTime       = *(double *)pgsub->q;
  I208               = *(long *)pgsub->o;
  I209               = *(long *)pgsub->p;
  
  azdiffSC =  azcapturedSC - azbaseSC;
  if( azdiffSC < 0 )
    azdiffSC += TWO_POWER_24;

  eldiffSC =  elcapturedSC - elbaseSC;
  if( eldiffSC < 0 )
    eldiffSC += TWO_POWER_24;
  
  /* Diagnostics to try and understand bad time stamps */
  if (capturedTime != prevCapturedTime) {
    if (prevCapturedTime != 0.0) {
      /*printf ("New captured time: captured Time = %f
                prevCapturedTime = %f
                capturedSC = %f
                baseSC =  %f servoFreq = %f\n", capturedTime,
                prevCapturedTime, capturedSC, baseSC,servoFreq) ;
    */ 
    } 
    prevCapturedTime = capturedTime;
  }

  /* 2's complement for negative velocities */

  if( azcapturedVelC > TWO_POWER_24/2 )
    azcapturedVelC -= TWO_POWER_24;

  if( elcapturedVelC > TWO_POWER_24/2 )
    elcapturedVelC -= TWO_POWER_24;

  if ( (azcountsPerDegree != 0.0) && (azservoFreq != 0.0))
  {
     if (azservoFreq != 0.0 )
     {
         /*azrawTime =  capturedTime + azdiffSC/azservoFreq; */
         azrawTime =  capturedTime;
         aaa[0]    =  azrawTime;
     }
     
     if( (I208 != 0.0) && (azcountsPerDegree != 0.0) )
     {
         aaa[1]  = (double) ((double)azcapturedPosC/((double)I208*(double)azcountsPerDegree));
         azrawPos = aaa[1];
     }
     else
     {
         azrawPos = aaa[1]  = (double) 370.0;
     }

     if( (I209 != 0.0) && (azcountsPerDegree != 0.0) )
         azrawVel = aaa[2]  = (azcapturedVelC/(I209*azcountsPerDegree))*azservoFreq;
     else
         azrawVel = aaa[2]  = 3.0;
  }

     if ( (elcountsPerDegree != 0.0) && (elservoFreq != 0.0))
  {
     if (elservoFreq != 0.0 )
         elrawTime = bbb[0] = capturedTime + eldiffSC/elservoFreq;

     if( (I208 != 0.0) && (elcountsPerDegree != 0.0) )
         elrawPos = bbb[1]  = elcapturedPosC/(I208*elcountsPerDegree);
     else
         elrawPos = bbb[1]  = 92.74;
     
     if( (I208 != 0.0) && (elcountsPerDegree != 0.0) )
         elrawVel = bbb[2]  = (elcapturedVelC/(I209*elcountsPerDegree))*elservoFreq;
     else
         elrawVel = bbb[2]  =  1.0;
  }

  /* The following limiting is intended only to trap corrupted values not to
   *  limit the returned data to the same range as a user is allowed to
   *  demand
   */
  /* azimuth */
  if (azrawPos > AZ_MAX_POS) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp posn. > 367.67 degs.");
     azrawPos = AZ_MAX_POS;
  } else if (azrawPos < AZ_MIN_POS) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp posn. < -188.25 degs.");
     azrawPos = AZ_MIN_POS;
  } else if (azrawVel > AZ_MAX_VEL) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp vel. > 2.0 degs/s");
     azrawVel = AZ_MAX_VEL ;
  } else if (azrawVel < AZ_MIN_VEL) {
     strcpy (dtHealth, "BAD") ;
     strcpy (dtHealthMess, "Time stamp vel. < -2.0 degs/s");
     azrawVel = AZ_MIN_VEL;
  } 

  /* elevation */
  if (elrawPos > EL_MAX_POS) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp posn. > 92.73 degs.");
     elrawPos = EL_MAX_POS;
  } else if (elrawPos < EL_MIN_POS) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp posn. < 0.0 degs.");
     elrawPos = EL_MIN_POS;
  } else if (elrawVel > EL_MAX_VEL) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp vel. > 0.75 degs/s");
     elrawVel = EL_MAX_VEL ;
  } else if (elrawVel < EL_MIN_VEL) {
     strcpy (dtHealth, "BAD");
     strcpy (dtHealthMess, "Time stamp vel. < -0.75 degs/s");
     elrawVel = EL_MIN_VEL;
  } 

  /* Perform running average over 10 previous Azimuth velocities */

  azvel[ii] = azrawVel;
  ii++;
  ii = ii%10;

  aztotalVel = 0;
  for( i=0; i<10; i++ )
    aztotalVel += azvel[i];

  aaa[2] = aztotalVel/10.0;

  /* Perform running average over 10 previous Elevation velocities */

  elvel[ii] = bbb[2];
  ii++;
  ii = ii%10;

  eltotalVel = 0;
  for( i=0; i<10; i++ )
    eltotalVel += elvel[i];

  bbb[2] = eltotalVel/10.0;

/* Compare the captured time with the raw time from the Bancomm and set the
*  health accordingly. Tests have shown that when things are working normally
*  the call to timeNow occurs approx 0.096 seconds after the servo counter
*  is latched by the PMAC. This offset is subtracted off to get as close
*  as possible to times measured at the same instant.
*/

  timeNow(&tai) ;
  deltaT = tai - azrawTime;


  /*printf("*********************\n");
  printf("deltaT = %f\n",deltaT);
  printf("tai = %f\n",tai);
  printf("azrawTime = %f\n",azrawTime);
  printf("capturedTime = %f\n",capturedTime);
  printf("azdiffSC = %f\n",azdiffSC);
  printf("azCapturedSC = %f\n",azcapturedSC);
  printf("azbaseSC = %f\n",azbaseSC);
  printf("azServoFreq = %f\n",azservoFreq);
 */ 
  
  
  if (deltaT > 1.0 || deltaT < -1.0) {
    strcpy (dtHealth, "BAD") ;
    strcpy (dtHealthMess, "Time stamp discrepancy > 1s") ;
    prevCapturedTime = aaa[0] = bbb[0] = tai ;
  } else {
    prevCapturedTime = aaa[0] = azrawTime ;
    bbb[0] = elrawTime ;
  }

  *(double *)pgsub->vala = deltaT;
  *(double *)pgsub->valb = aaa[0];
  *(double *)pgsub->valc = aaa[1]; 
  *(double *)pgsub->vald = aaa[2]; 
  *(double *)pgsub->vale = bbb[0];
  *(double *)pgsub->valf = bbb[1];
  *(double *)pgsub->valg = bbb[2]; 
  *(long *)pgsub->valh   = (long)1;     /* Set the time strobe bit */
  strcpy (pgsub->vali, dtHealth);
  strcpy (pgsub->valj, dtHealthMess);



  return(0);
}

/* 
 *  INPUTS:
 *      pcad->a = Which axis to stop assert.              (LONG).
 *                0 = AZ
 *                1 = EL
 * 
 *  OUTPUTS:
 *      pcad->vala = Which axis to stop assert. AZ/EL     (STRING).
 *      pcad->valb = Apply Brakes to Az  YES.             (STRING).
 *      pcad->valc = Apply Brakes to El  YES.             (STRING).
 *      pcad->vald = Debug Level         1                (STRING).
 */

long assertStop (struct genSubRecord *pgsub)
{
    long card;

    card = (long)(*(double *)pgsub->a);

    if (card == 0)
        strcpy(pgsub->vala, "AZ");
    else
	strcpy(pgsub->vala, "EL");

    strcpy (pgsub->valb, "YES");
    strcpy (pgsub->valc, "YES");
    strcpy (pgsub->vald, "1");

    printf("assertSTOP \n");
    
    return(0);
}

/* 
 *  INPUTS:
 *      pcad->a = Current trackId.                        (DOUBLE).
 *      pcad->b = Follow Flag.                            (LONG).
 *      pcad->c = new trackId.                            (DOUBLE).
 * 
 *  OUTPUTS:
 *      pcad->vala =      (LONG).
 */

long CalcNewId (struct genSubRecord *pgsub)
{
double trackId;
double newId;
long   followFlag;

    trackId    = *(double *)pgsub->a;
    followFlag = *(long *)pgsub->a;
    newId      = *(double *)pgsub->a;

	printf("trackId = %f\n", trackId);
	printf("newId = %f\n", newId);
	printf("followFlag = %ld\n", followFlag);

    if ( followFlag && (trackId != newId) )
    {
	printf("cambio trackId\n");
        *(long *)pgsub->vala = (long)1; 
    }
    else
        *(long *)pgsub->vala =(long)0; 
    
    return(0);
}
epicsRegisterFunction(initSetPositions);
epicsRegisterFunction(SetPositions);
epicsRegisterFunction(engToDeg);
epicsRegisterFunction(setAxisState);
epicsRegisterFunction(inPositionCalc);
epicsRegisterFunction(assertStop);
epicsRegisterFunction(capturedPos);
