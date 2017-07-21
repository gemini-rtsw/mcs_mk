#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsThread.h>
#include <epicsPrint.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <subRecord.h>
#include <genSubRecord.h>
#if 0
#include <mcssir.h>
#include <mcscad.h>
#include <mcs.h>
#endif
#include <cadRecord.h>
#include <cad.h>
#include <menuCarstates.h>
#include <timeLib.h>

/* Modes (pgsub-a).
 */
#define	CONTINUOUS	0
#define	CONTROLLED	1

/* Enable/Disable (pgsub-b)
 */
#define	ENABLE		1
#define	DISABLE		0

/* Debug flag.
 */
#define	DEBUG_TEST	0	/* 0=no, 1=yes */


/*
 * pgsub->a  0 = Continuous slew/tracking mode of both axes.	(DOUBLE)
 *           1 = More controlled mode.
 * pgsub->b  0 = Off for mode 1 above.				(DOUBLE)
 *           1 = On for mode 1 above.
 * pgsub->c  Azimuth velocity in deg/s for mode 1		(DOUBLE)
 * pgsub->d  Elevation velocity in deg/s for mode 1		(DOUBLE)
 * pgsub->e  Azimuth						(DOUBLE)
 * pgsub->f  Elevation						(DOUBLE)
 */

long testFollow (struct genSubRecord *pgsub)
{
    int           error;
    static int    azFactor, elFactor;
    static int    first = 1;
    static double applyT;
    double        rawT;
    double        array[5];
    double        azStep, elStep;

    do {
	error = timeNow(&rawT);
	epicsThreadSleep(1);
    } while (error);

    applyT = rawT + 0.05;

    /* Continuous slew?
     */
    if ((*(double *)pgsub->a) == CONTINUOUS)
    {
	if (*(double *)pgsub->b == ENABLE)
	{

#if DEBUG_TEST
if (first) printErr ("testFollow: Continuous slew enabled\n");
#endif

	    azStep = 0.1 * 0.05;
	    elStep = 0.1 * 0.05;
	    if (first)
	    {
		*(double *)pgsub->e = 90.0;
		*(double *)pgsub->f = 40.0;
		azFactor            = 1;
		elFactor            = 1;
		first               = 0;
		applyT              = rawT + 0.05;
	    }
	    else
	    {
		*(double *)pgsub->e += azFactor * azStep;
		*(double *)pgsub->f += elFactor * elStep;
		applyT              += 0.05;
	    }

	    if (*(double *)pgsub->e > 120.0)
	    {
		*(double *)pgsub->e = 80.0;
		azFactor            = -1;
	    }
	    else if (*(double *)pgsub->e < 50.0)
	    {
		*(double *)pgsub->e = 90.0;
		azFactor            = 1;
	    }

	    if ((elFactor == 1) && (*(double *)pgsub->f > 50.0))
	    {
		*(double *)pgsub->f = 85.0;
		elFactor            = -1;
	    }

	    if ((elFactor == -1) && (*(double *)pgsub->f < 55.0))
	    {
		*(double *)pgsub->f = 40.0;
		elFactor            = 1;
	    }
	}
	else {
#if DEBUG_TEST
if (!first) printErr ("testFollow: Continuous slew disabled\n");
#endif
	    first = 1;
	}
    }
    else
    {
	if (*(double *)pgsub->b == ENABLE)
	{
#if DEBUG_TEST
if (first) printErr ("testFollow: Controlled slew enabled\n");
#endif
	    if (first)
	    {
		first  = 0;
		applyT = rawT + 0.05;
	    }
	    else
		applyT += 0.05;

	    azStep               = (*(double *)pgsub->c) * 0.05;
	    elStep               = (*(double *)pgsub->d) * 0.05;
	    *(double *)pgsub->e += azStep;
	    *(double *)pgsub->f += elStep;
	}
	else
	{
#if DEBUG_TEST
if (!first) printErr ("testFollow: Controlled slew disabled\n");
#endif
	    first = 1;
	}
    }

#if DEBUG_TEST
printErr ("first = %d, time = %f, Az = %f, El = %f\n", first, applyT, *(double *)pgsub->e, *(double *)pgsub->f);
#endif

    array[0] = rawT;
    array[1] = applyT;
    array[2] = rawT;
    array[3] = *(double *)pgsub->e;
    array[4] = *(double *)pgsub->f;
    memcpy (pgsub->vala, array, 5 * sizeof(double));

    return(0);
}
epicsRegisterFunction(testFollow);
