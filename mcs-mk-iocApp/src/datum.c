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

#include <cadRecord.h>
#include <cad.h>
#include <menuCarstates.h>


/* 
 * Calculates current Az wrap and sets the direction
 * of travel when a datum is performed
 *
 * Inputs:
 *	pgsub->a = outer topple state (0,3=fault, 1=not toppled, 2 toppled)
 *	pgsub->b = inner topple state (0,3=fault, 1=not toppled, 2 toppled)
 *	pgsub->c = debug level
 *
 * Outputs:
 *	pgsub->vala = 1 if az in (-180, 0)  range, 0 otherwise
 *	pgsub->valb = 1 if az in (0, 180)   range, 0 otherwise
 *	pgsub->valc = 1 if az in (180, 360) range, 0 otherwise
 *	pgsub->vale = MCS_WRAP_A, MCS_WRAP_B, MCS_WRAP_C
 * 
 */
long calcWrap (struct genSubRecord *pgsub)
{
    long outer;
    long inner;
    long debug;

    /* Get arguments.
     */
    outer = *(long *) pgsub->a;
    inner = *(long *) pgsub->b;
    debug = *(long *) pgsub->c;

    if (mcGetSimuLevel())
    {
        printf("Simulating Calcwrap\n");
        *(long *) pgsub->vala = 0;
        *(long *) pgsub->valb = 1;
        *(long *) pgsub->valc = 0;
        *(long *) pgsub->vale = MCS_WRAP_B;
    } else
    {
        /* Outer: Toppled,  Inner: Not Toppled ? */
        if ((outer == 2) && (inner == 1))
        {						/* -180 < Az < 0 */
	    *(long *) pgsub->vala = 1;
	    *(long *) pgsub->valb = 0;
	    *(long *) pgsub->valc = 0;
	    *(long *) pgsub->vale = MCS_WRAP_A;
        }
        /* Outer: Not Toppled, Inner: Not Toppled ? */
        else if ((outer == 1) && (inner == 1))
        {						/* 0 < Az < 180 */
   	    *(long *) pgsub->vala = 0;
	    *(long *) pgsub->valb = 1;
	    *(long *) pgsub->valc = 0;
	    *(long *) pgsub->vale = MCS_WRAP_B;
        }
        /* Outer: Not Toppled, Inner: Toppled ? */
        else if ((outer == 1) && (inner == 2))
        {						/* 180 < Az < 360 */
	    *(long *) pgsub->vala = 0;
	    *(long *) pgsub->valb = 0;
	    *(long *) pgsub->valc = 1;
	    *(long *) pgsub->vale = MCS_WRAP_C;
        }
        else
        {
	    *(long *) pgsub->vala = 0;
	    *(long *) pgsub->valb = 0;
	    *(long *) pgsub->valc = 0;
	    *(long *) pgsub->vale = -1;
        }
    }

    return(0);
}

/* Not used anymore? */

long datumStop (struct genSubRecord *pgsub)
{
    long card;

    card = (long)(*(double *)pgsub->a);

    if (card == 0)
        strcpy(pgsub->vala, "AZ");
    else
        strcpy(pgsub->vala, "EL");

    strcpy (pgsub->valb, "NO");
    strcpy (pgsub->valc, "NO");
    strcpy (pgsub->vald, "1");

    return(0);
}


/* Start datum witch SONY switch
 *
 * Inputs:
 *	pgsub->a = axis to datum (0=az, 1=el)
 *	pgsub->b = position w/r to 45 deg switch (0=above, 1=below)
 *	pgsub->c = wrap range (0=(-180,0), 1=(0,180), 2=(180=360))
 *	pgsub->d = current position
 * Outputs:
 *	pgsub->vala = direction of homing move
 *      pgsub->valb = datum flag (0)
 */
long startDatumS (struct genSubRecord *pgsub)
{
    long   card;
    long   tilt;
    long   wrap;
    long   terminator;
    double curpos;
    char   command[MAX_STRING_SIZE];
    char   response[MAX_STRING_SIZE];
    char   errmsg[MAX_STRING_SIZE];

    /* Get input fields.
     */
    card   = (long)(*(double *) pgsub->a);
    tilt   = *(long *) pgsub->b;
    wrap   = *(long *) pgsub->c;
    curpos = *(double *) pgsub->d;

#ifdef TELESCOPE
	
    /* Set the Datumed Flag to False.
     */
     *(long *) pgsub->valb = 0;

    /* Check the axis to datum and determine the direction to move.
     */
    if (card == 0)	/* azimuth */
    {
	/* The direction of motion will depend on the current region.
	 * If the wrap is in the MCS_WRAP_A region (-180,0) then
	 * we have to move with positive speed. Otherwise we have to
	 * move with a negative speed.
	 */
	if (wrap == MCS_WRAP_A)
	    *(double *) pgsub->vala = AZ_I223_S;
	else if ((wrap == MCS_WRAP_B) || (wrap == MCS_WRAP_C) )
	    *(double *) pgsub->vala = -AZ_I223_S;
	else
	{
	    printf ("startDatumS: Invalid Topple Bracket Setting\n");
	    *(double *) pgsub->vala = 0.0;
	}
    }
    else		/* elevation */
    {
	if (tilt)
	    *(double *) pgsub->vala = EL_I223_S;	/* below 45 degrees */
	else
	    *(double *) pgsub->vala = -EL_I223_S;	/* above 45 degrees */
    }
#else
    /* For the stage */
    if (curpos > 0.0)
        *(double *) pgsub->vala = -EL_I223_S;
    else
	*(double *) pgsub->vala = EL_I223_S;
#endif

/* if simulating */
    if (mcGetSimuLevel())
    {
        printf("Simulating startDatumS\n");
        mcSimStartDatumS(card);
    } else
    {
        /* Set the home direction using the PMAC variable I223.
         */
        sprintf (command, "I223=%f", *(double *)pgsub->vala);
        terminator = drvPmacMbxWriteRead (card, command, response, errmsg);
        if (errmsg[0])
        {
	    printf ("startDatumS: PMAC command: Setting I223, Error: %s\n", errmsg);
	    return (1);
        }

        /* Set the home flags to point at the sony switch.
         */
        terminator = drvPmacMbxWriteRead (card, "I225=$53C000", response, errmsg);
        if (errmsg[0])
        {
	    printf ("startDatumS: PMAC command: I225=$53C000, Error: %s\n", errmsg);
	    return (1);
        }

        /* Make sure homing is done on falling edge.
         */
        terminator = drvPmacMbxWriteRead (card, "I902=10", response, errmsg);
        if (errmsg[0])
        {
	    printf ("startDatumS: PMAC command: I902=10, Error: %s\n", errmsg);
	    return (1);
        }

        /* Issue "home" command.
         */
        terminator = drvPmacMbxWriteRead (card, "#2home", response, errmsg);
        if (errmsg[0])
        {
	    printf ("startDatumS: PMAC command: #2home, Error: %s\n", errmsg);
	    return (1);
        }
    }

    return(0);
}


/* End datum with Sony switch. The record calling this routine processes
 * every five seconds.
 *
 * Inputs:
 *	pgsub->a = direction of homing move
 *	pgsub->b = switch positive counts
 *	pgsub->c = switch negative counts
 *	pgsub->d = last command issued (e.g. MCS_DATUM)
 *	pgsub->e = axis to datum (0=az, 1=el)
 *	pgsub->f = debug level
 *	pgsub->g = datum mechanism (MCS_SWITCH, MCS_HEAD)
 *	pgsub->h = home complete
 *	pgsub->i = desired velocity zero
 *	pgsub->j = in position
 *	pgsub->k = home search in progress
 *	pgsub->l = internal use - old value of home search in progress
 *	pgsub->m = internal use
 *
 * Outputs:
 *	pgsub->vala = select mask (0=not done, 3=done)
 *	pgsub->valb = datum flag (0, 1)
 *
 */
long endDatumS (struct genSubRecord *pgsub)
{
    double direction;
    double switchPos;
    double switchNeg;
    long   cmd;
    long   card;
    long   terminator;
    long   debug;
    long   mech;
    long   hc;
    long   dvz;
    long   inpos;
    long   hsip;
    long   oldhsip;
    char   command[MAX_STRING_SIZE];
    char   response[MAX_STRING_SIZE];
    char   errmsg[MAX_STRING_SIZE];

    direction = *(double *) pgsub->a;
    switchPos = *(double *) pgsub->b;
    switchNeg = *(double *) pgsub->c;
    cmd       = *(long *) pgsub->d;
    card      =  (long)(*(double *) pgsub->e);
    debug     = *(long *) pgsub->f;
    mech      = *(long *) pgsub->g;
    hc        = *(long *) pgsub->h;
    dvz       = *(long *) pgsub->i;
    inpos     = *(long *) pgsub->j;
    hsip      = *(long *) pgsub->k;
    oldhsip   = *(long *) pgsub->l;


/* if simulating */
  if (mcGetSimuLevel() && (cmd == MCS_DATUM) && (mech == MCS_SWITCH) && (*(long *)pgsub->m) &&  hc && dvz && inpos)
  {
      printf("Simulating endDatumS\n");
      mcSimEndDatumS(card);

      /* Set sequence mask to mark datum processed.
       */
      *(long *) pgsub->vala = 3;

      /* Set the Datumed Flag to True.
       */
      *(long *) pgsub->valb = 1;

      /* Set internal flag back to 0 (FALSE).
       */
      *(long *) pgsub->m = 0;
  } else
  {

    /* Check whether the home search was in progress and it's not anymore.
     * Set a flag if that's the case.
     */
    if (oldhsip && !hsip)
    {
	*(long *)pgsub->m = 1;
	if( debug )
	    printf("Home search was in progress and not anymore\n");
    }

    /* Process only if the last command was DATUM, if we are using the
     * switch, if the home search was in progress and now it's not, if
     * the home search completed, if the desired velocity is zero, and
     * if we are in position (and if today is not my birthday).
     */
    if ((cmd == MCS_DATUM) && (mech == MCS_SWITCH) && (*(long *)pgsub->m) &&
        hc && dvz && inpos)
    {
	if (debug)
	    printf("endDatumS: Do something\n");

	if (direction > 0)
	{
	    sprintf (command, "M262=M262+%f", switchNeg);
	    if (debug)
		printf ("Using negative switch value: %s\n", command);
	}
	else
	{
	    sprintf (command, "M262=M262+%f", switchPos);
	    if (debug)
		printf ("Using positive switch value: %s\n", command);
	}

	/* Open the loop.
	 */
	terminator = drvPmacMbxWriteRead (card, "#2K", response, errmsg);

	/* Download new value to Actual Position Register.
	 */
	terminator = drvPmacMbxWriteRead (card, command, response, errmsg);

	/* Set sequence mask to mark datum processed.
	 */
	*(long *) pgsub->vala = 3;

	/* Set the Datumed Flag to True.
	 */
	*(long *) pgsub->valb = 1;

	/* Set internal flag back to 0 (FALSE).
	 */
	*(long *) pgsub->m = 0;
    }
    else
    {
	*(long *) pgsub->vala = 0;	/* datum didn't process */
	if (debug)
	    printf ("endDatumS: Do nothing\n");
    }

    /* Save value of home search in progress for next iteration.
     */
    *(long *)pgsub->l = hsip;
  }

    return(0);
}


/* Start datum with tape encoder.
 *
 * Inputs:
 *	pgsub->a = axis to datum (0=az, 1=el)
 *	pgsub->b = position w/r to 45 deg switch (0=above, 1=below)
 *	pgsub->c = wrap range (0=(-180,0), 1=(0,180), 2=(180=360))
 *	pgsub->d = current position
 *	pgsub->e = head number (MCS_HEAD_#)
 *
 * Outputs:
 *	pgsub->vala = direction of homing move
 *      pgsub->valb = datum flag (0)
 */
long startDatumH (struct genSubRecord *pgsub)
{
    long   card;
    long   tilt;
    long   wrap;
    long   head;
    long   terminator;
    double curpos;
    char   command[MAX_STRING_SIZE];
    char   response[MAX_STRING_SIZE];
    char   errmsg[MAX_STRING_SIZE];

    card   = (long)(*(double *)pgsub->a);
    tilt   = *(long *)pgsub->b;
    wrap   = *(long *)pgsub->c;
    curpos = *(double *)pgsub->d;
    head   = *(long *)pgsub->e;

#ifdef TELESCOPE

    /* Set the Datumed Flag to False.
     */
     *(long *) pgsub->valb = 0;

    /* Check the axis to datum and determine the direction to move.
     */
    if (card == 0)	/* azimuth */
    {
	/* The direction of motion will depend on the current region.
	 * If the wrap is in the MCS_WRAP_A region (-180,0) then
	 * we have to move with positive speed. Otherwise we have to
	 * move with a negative speed.
	 */
	if (wrap == MCS_WRAP_A)
	    *(double *)pgsub->vala = AZ_I223_H;
	else if ((wrap == MCS_WRAP_B) || (wrap == MCS_WRAP_C))
	    *(double *)pgsub->vala = -AZ_I223_H;
	else
	{
	    printf ("startDatumH: Invalid Topple Bracket Setting\n");
	    *(double *) pgsub->vala = 0.0;
	}
    }
    else		/* elevation */
    {
	if (tilt)
	    *(double *)pgsub->vala = EL_I223_H;		/* below 45 degrees */
	else
	    *(double *)pgsub->vala = -EL_I223_H;	/* above 45 degrees */
    }
#else
    /* For the stage */
    if (curpos > 0.0)
        *(double *) pgsub->vala = -EL_I223_H;
    else
        *(double *) pgsub->vala = EL_I223_H;
#endif

    /* Set the home direction using the PMAC variable I223.
     */
    sprintf (command, "I223=%f", *(double *) pgsub->vala);
    terminator = drvPmacMbxWriteRead(card, command, response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: Setting I223, Error: %s\n", errmsg);
	return (1);
    }

    /* Set the home flags to point at the correct head.
     * P308 controls which head to use by the PLC program.
     */
    if (head == MCS_HEAD_1)
        strcpy (command, "P308=1");
    else if (head == MCS_HEAD_2)
        strcpy (command, "P308=2");
    else if (head == MCS_HEAD_3)
        strcpy (command, "P308=3");
    else if (head == MCS_HEAD_4)
        strcpy (command, "P308=4");

    terminator = drvPmacMbxWriteRead (card, command, response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: %s, Error: %s\n", command, errmsg);
	return (1);
    }

    /* Set the tape orientation correction on the PMAC side (MORE INFO).
     */
    if (card == 0)
        strcpy (command, "P313=-1");
    else if( card == 1 )
    {
	if (head == MCS_HEAD_1)
	    strcpy (command, "P313=1");
	else if (head == MCS_HEAD_2)
	    strcpy (command, "P313=-1");
    }

    terminator = drvPmacMbxWriteRead (card, command, response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: %s, Error: %s\n", command, errmsg);
	return (1);
    }

    /* Set the mark number correction on the PMAC side (MORE INFO).
     */
    if (card == 0)
        strcpy (command, "P314=0");
    else if (card == 1)
    {
	if(head == MCS_HEAD_1)
	    strcpy (command, "P314=-1");
	else if (head == MCS_HEAD_2)
	    strcpy (command, "P314=0");
    }

    terminator = drvPmacMbxWriteRead (card, command, response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: %s, Error: %s\n", command, errmsg);
	return (1);
    }

    /* Set the flag to enable the PLC program.
     */
    terminator = drvPmacMbxWriteRead (card, "P300=1", response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: P300=1, Error: %s\n", errmsg);
	return (1);
    }

    /* Enable PLC 6 - This performs the datum.
     */
    terminator = drvPmacMbxWriteRead (card, "enable plc 6", response, errmsg);
    if (errmsg[0])
    {
	printf ("startDatumH: PMAC command: enable plc 6, Error: %s\n", errmsg);
	return (1);
    }

    return (0);
}


/* End datum with tape encoder.
 *
 * Inputs:
 *	pgsub->a = direction of homing move
 *	pgsub->b = last command issued (e.g. MCS_DATUM)
 *	pgsub->c = axis to datum (0=az, 1=el)
 *	pgsub->d = debug level
 *	pgsub->e = datum mechanism (MCS_SWITCH, MCS_HEAD_#)
 *	pgsub->f = outer topple position
 *	pgsub->g = correction polynomial coefficients for Azimuth, tape head 1
 *	pgsub->h = correction polynomial coefficients for Azimuth, tape head 2
 *	pgsub->i = correction polynomial coefficients for Azimuth, tape head 3
 *	pgsub->k = correction polynomial coefficients for Azimuth, tape head 4
 *	pgsub->l = pitches to encoder counts conversion factor
 *	pgsub->m = array of positions of first az tape mark w/r to each head
 *	pgsub->n = outer topple state
 *	pgsub->o = reference mark width
 *	pgsub->p = counts per degree
 *
 * Outputs:
 *	pgsub->vala = select mask (0=not done, 3=done, 4=car error)
 *	pgsub->valb = datum flag
 *
 */
long endDatumH (struct genSubRecord *pgsub)
{
    double direction;
    double numPEC;
    double outerTopplePos;
    double pitchesToEC;
    double p[11];
    double firstMark[4];
    double datumPos;
    double *ptr = NULL;
    double M262;
    double firstRef = 0;
    double refMarkWidth;
    double countsPerDegree;
    double corr;
    double ap = 0;
    double ap360 = 0;
    long   cmd;
    long   card;
    long   terminator;
    long   debug;
    long   mech;
    long   P304;
    long   P307;
    long   numPitch;
    long   etest;
    long   OM = 0;
    long   outerToppleStat;
    char   command[MAX_STRING_SIZE];
    char   response[MAX_STRING_SIZE];
    char   errmsg[MAX_STRING_SIZE];
    int    i;

    direction       = *(double *)pgsub->a;
    cmd             = *(long *)pgsub->b;
    card            =  (long)(*(double *)pgsub->c);
    debug           = *(long *)pgsub->d;
    mech            = *(long *)pgsub->e;
    outerTopplePos  = *(double *)pgsub->f;
    pitchesToEC     = *(double *)pgsub->l;
    outerToppleStat = *(long *)pgsub->n;
    refMarkWidth    = *(double *)pgsub->o;
    countsPerDegree = *(double *)pgsub->p;


     /* Process only if the last command was DATUM and if we are
      * using any of the the heads.
      */
    if ((cmd == MCS_DATUM) && (mech != MCS_SWITCH))
    {
	if (debug)
	    printf("endDatumH: Polling P304\n");

	/* Check whether the PLC program is running. The P304 variable
	 * will change to zero when datum has finished.
	 */
	terminator = drvPmacMbxWriteRead (card, "P304", response, errmsg);
	sscanf (response, "%ld", &P304);
	if (P304 == -1)		/* error */
	{
	    *(long *)pgsub->vala = 4;	/* set car error */
	    if (debug)
		printf("endDatumH: Error occurred with Datum procedure\n");

	}
	else if (P304 != 0)	/* still running */
	{
	    *(long *)pgsub->vala = 0;  /* Do not process record down stream */
	    switch (P304)
	    {
	    case 1:
		printf ("endDatumH: PLC 6 running\n");
		break;

	    case 2:
		printf ("endDatumH: Homing to 1st mark\n");
		break;

	    case 3:
		printf ("endDatumH: Homing to 2nd mark\n");
		break;

	    case 4:
		printf ("endDatumH: Calculate mark number\n");
		break;

	    default:
		break;
	    }
	}
	else if (P304 == 0)	/* datum has finished */
	{
	    /* Disable PLC program by setting P300 to zero.
	     */
	    terminator = drvPmacMbxWriteRead (card, "P300=0", response, errmsg);
	    if(errmsg[0])
	    {
		printf ("endDatumH: PMAC command: P300=0, Error: %s\n", errmsg);
		return (1);
	    }

	    /* Get the reference mark number (P307) and use this number
	     * to get the (MORE INFO).
	     */
	    terminator = drvPmacMbxWriteRead (card, "P307", response, errmsg);
	    sscanf (response, "%ld", &P307);
	    if (card == 0)		/* azimuth */
		OM = 0;
	    else if (card == 1)		/* elevation */
	    {
		if (mech == MCS_HEAD_1)
		    OM = 138000;
		else if (mech == MCS_HEAD_2)
		    OM = 72000;
	    }

	    /* Calculate the number of pitches from first reference mark.
	     */
	    numPitch = (P307 - 1) * 1000;
	    etest    = P307 % 2;
	    if (!etest)
	        numPitch += P307 / 2;
	    numPitch -= OM;

	    /* Convert number of pitches to encoder counts (5 milliarcsec).
	     */
	    numPEC = pitchesToEC * numPitch;

	    /* Copy the 10th order polynomial for the selected head into
	     * a temporary array.
	     */
	    if (mech == MCS_HEAD_1)
	        ptr = (double *)pgsub->g;
	    else if (mech == MCS_HEAD_2)
	        ptr = (double *)pgsub->h;
	    else if (mech == MCS_HEAD_3)
	        ptr = (double *)pgsub->i;
	    else if (mech == MCS_HEAD_4)
	        ptr = (double *)pgsub->k;
	    for (i=0; i<11; i++)
		p[i] = *(ptr++);

	    /* Calculate correction using the 10th order polynomial.
	     */
	    corr = p[0] + p[1]*numPEC + p[2]*pow(numPEC,2) +
		   p[3]*pow(numPEC,3) + p[4]*pow(numPEC,4) +
		   p[5]*pow(numPEC,5) + p[6]*pow(numPEC,6) +
		   p[7]*pow(numPEC,7) + p[8]*pow(numPEC,8) +
		   p[9]*pow(numPEC,9) + p[10]*pow(numPEC,10);

	    /* The datum position will be the calculated encoder counts
	     * minus the correction.
	     */
	    datumPos = numPEC - corr;

	    /* Check whether we have to move in the positive direction.
	     * If that's the case, the datum position needs a change.
	     */
	    if (direction > 0)
	    {
		if (card == 0)		/* az */
		    datumPos -= refMarkWidth;
		else if (card == 1)	/* el */
		{
		    if (mech == MCS_HEAD_1)
		        datumPos += refMarkWidth;
		    else if (mech == MCS_HEAD_2)
		        datumPos -= refMarkWidth;
		}
	    }

	    /* Copy array of first Az tape mark with reference to each
	     * head into a temporary array.
	     */
	    ptr = (double *)pgsub->m;
	    for (i=0; i<4; i++)
		firstMark[i] = *(ptr++);

	    /* Get reference based on head being used.
	     */
	    if (mech == MCS_HEAD_1)
	        firstRef = firstMark[0];
	    else if (mech == MCS_HEAD_2)
	        firstRef = firstMark[1];
	    else if (mech == MCS_HEAD_3)
	        firstRef = firstMark[2];
	    else if (mech == MCS_HEAD_4)
	        firstRef = firstMark[3];

	    /* (MORE INFO)
	     */
	    if (card == 0)		/* az */
	        ap360 = firstRef - datumPos;
	    else if (card == 1)		/* el */
	    {
		if (mech == MCS_HEAD_1)
		    ap360 = firstRef + datumPos;
		else if (mech == MCS_HEAD_2)
		    ap360 = firstRef - datumPos;
	    }

	    /* Normalize (MORE INFO) to 0-360 range.
	     */
	    if (ap360 < 0.0)
		ap360 += 360.0 * countsPerDegree;

	    if (card == 0)		/* az */
	    {
	        printf("AP360 = %f \n",ap360);

		if (outerToppleStat == 1)	/* not toppled */
		{
		    if (ap360 < outerTopplePos)
			ap = ap360 + 360.0 * countsPerDegree;
		    else
			ap = ap360;

		}
		else if( outerToppleStat == 2 )	/* toppled */
		{
		    if (ap360 > outerTopplePos)
			ap = ap360 - 360.0 * countsPerDegree;
		    else
			ap = ap360;

		}
		else
		    printf ("Outer Topple Bracket Status is in error: %ld\n", outerToppleStat);
	    }
	    else if( card == 1 )	/* el */
		ap = ap360;

	    /* Open the loop
	     */
	    terminator = drvPmacMbxWriteRead(card, "#2K", response, errmsg);

	    /* Diagnostics for John
	     */
	    sprintf (command, "P309=%f", ap);
	    terminator = drvPmacMbxWriteRead (card, command, response, errmsg);

	    /* Download new value to Actual Position Register.
	     */
	    sprintf (command, "M262=M262+%f", ap);
	    terminator = drvPmacMbxWriteRead (card, command, response, errmsg);

	    /* Get value back (what for?).
	     */
	    terminator = drvPmacMbxWriteRead (card, "M262", response, errmsg);
	    sscanf (response, "%lf", &M262);

	    /* Set sequence mask.
	     */
	    *(long *)pgsub->vala = 3;	/* datum processed */

	    /* Set the Datumed Flag to True
	     */
	    *(long *)pgsub->valb = 1;
	}
    }
    else
    {
	*(long *)pgsub->vala = 0;	/* nothing done */
	if (debug)
	    printf ("endDatumH: Do nothing\n");
    }

    return(0);
}

/* Close the Loop Position
 *
 * Inputs:
 *	pgsub->a = axis to close the loop (0=az, 1=el)
 * Outputs:
 */
long closeLoop (struct genSubRecord *pgsub)
{
    long   card;
    long   terminator;
    char   response[MAX_STRING_SIZE];
    char   errmsg[MAX_STRING_SIZE];

    /* Get input fields.
     */
    card   = (long)(*(double *) pgsub->a);

    /* Issue "Close Loop" command.
     */
    terminator = drvPmacMbxWriteRead (card, "#2J/", response, errmsg);
    if (errmsg[0])
    {
	printf ("closeLoop: PMAC command: #2J/, Error: %s\n", errmsg);
	return (1);
    }

printf("Loop closed \n");
    return(0);
}
epicsRegisterFunction(endDatumH);
epicsRegisterFunction(endDatumS);
epicsRegisterFunction(closeLoop);
epicsRegisterFunction(startDatumH);
epicsRegisterFunction(startDatumS);
epicsRegisterFunction(calcWrap);
