#include <stdio.h>
#include <math.h>
#include <epicsPrint.h>

#define TIME_INT        0.005  /* 5 msec                             */
#define TRIGGER_LATENCY 0.1    /* Seconds before Bancomm trigger     */
#define JUMP            0.1    /* Degrees change considered a slew   */
#define AZ_JUMP         0.1    /* Degrees change considered a slew   */
#define EL_JUMP         0.1    /* Degrees change considered a slew   */
#define LOG_LIMIT       72000  /* One hour of TCS logging capability */
#define NUM_EXTRAP	20	/* number of points to extrapolate    */
#define	DOUBLE_BUFF	(NUM_EXTRAP>10)
#define	LOGGING_ON	TRUE
#define AZ_MAX_ACC      0.1
#define EL_MAX_ACC      0.05


#define MIN(x,y)	((x<y)?x:y)
#define MIN3(a,b,c)	((a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c))

long fillBuffer		(double *, double *, double *, double *, double *,
			 double, long, double *, double, double, double,
                         double);
long calc_coeffs	(double *, double *, double *, double *, double *,
			 double *);
int calc_linear		(double, double, double, double, double, double,
			 double, double *, double *, double *, double, double);
int calc_quadratic	(double, double, double, double, double, double,
			 double, double *, double *, double * );
int fit_new_demand      (double, double, double *, double, double *, double,
                         double *, double, double, double, long );


#ifdef OLD_LOGGING
long   tcsjj = 0;
double tcsTT[LOG_LIMIT];
double tcsAz[LOG_LIMIT];
double tcsEl[LOG_LIMIT];
long   azjj = 0;
long   eljj = 0;
double faztt[96000];
double fazpos[96000];
double fazvel[96000];
double feltt[96000];
double felpos[96000];
double felvel[96000];
long   tcsjj = 0;
double tcsTT[96000];
double tcsAz[96000];
double tcsEl[96000];
long   azCounter = 0;
double azAA[96000];
double azBB[96000];
double azCC[96000];
long   afCounter = 0;
double azFit1[96000];
double azFit2[96000];
double azFit3[96000];
long logging = 0;
#endif
FILE  *fd, *fi, *vels;

/*
 * This routine is at the heart of tracking in the MCS.
 *
 * Inputs:
 * -------
 *    pgsub->a = Array of 5 doubles.
 *    pgsub->b = Array of 5 doubles.
 *    pgsub->c = Array of 5 doubles.
 *    pgsub->d = Which one of the above was most recent?    LONG.
 *    pgsub->e = Follow Flag                                LONG.
 *    pgsub->f = Current Track Id                           DOUBLE.
 *    pgsub->i = Internal use:				    LONG.
 *               Previous recent sample
 *    pgsub->k = Not used                                   LONG.
 *    pgsub->j = Not used				    LONG.
 *    pgsub->l = Not used				    DOUBLE.
 *    pgsub->q = Handshake bit from Az. PMAC motion program DOUBLE.
 *    pgsub->r = Handshake bit from El. PMAC motion program DOUBLE.
 *
 * Outputs:
 * --------
 *    pgsub->vala = Array of NUM_EXTRAP Azimuth Positions           DOUBLE.
 *    pgsub->valb = Array of NUM_EXTRAP Azimuth Velocities          DOUBLE.
 *    pgsub->valc = Array of NUM_EXTRAP Elevation Positions         DOUBLE.
 *    pgsub->vald = Array of NUM_EXTRAP Elevation Velocities        DOUBLE.
 *    pgsub->vale = Mask for fanout                         LONG.
 *                  1  (Link 1) = Set trackId.
 *                  2  (Link 2) = Fill Az. buffer.
 *                  4  (Link 3) = Fill El. buffer.  
 *                  8  (Link 4) = Set time interrupt.
 *                  16 (Link 5) = Set Car Error.
 *    pgsub->valf = Time for external Bancomm Trigger       DOUBLE.
 *    pgsub->valg = TrackId                                 DOUBLE.
 *    pgsub->valh = Current Network time delay (sec)        DOUBLE.
 *    pgsub->vali = Number of samples missed                LONG.
 *    pgsub->valj = Fill bottom/top of Az. buffer (1/2)     LONG.
 *    pgsub->valk = Fill bottom/top of El. buffer (1/2)     LONG.
 *    pgsub->vall = Error string                            LONG.
 *
*/

long test ()
{
    int    i;
    double pos1[NUM_EXTRAP];
    double pos2[NUM_EXTRAP];
    double vel[NUM_EXTRAP];
    /* Removed from EPICS 7 Migration
    double tt, tt2;
    */
    double tt;

    double lastVel = -0.007688;
    double lastPos = 62.56433468;
    double acceleration = -0.05;
    /* Extrapolate data. Data points are extrapolated from the starting
     * time offset + TIME_INT (0.005) to time offset + NUM_EXTRAP * TIME_INT.
     */
     for (i=0; i<NUM_EXTRAP; i++)
     {
            tt       = (double)i*TIME_INT; 
	    /* Removed from EPICS 7 Migration
            tt2      = i*TIME_INT; 
	    */

            pos1[i] = lastPos + lastVel*tt + (double)0.5*acceleration*tt*tt;
            pos2[i] = lastPos + lastVel*tt + 0.5*acceleration*tt*tt;
            vel[i] = lastVel + acceleration*tt;
     }

     for (i=0; i<NUM_EXTRAP; i++)
        {
            errlogPrintf("pos1[%d] = %.8f  ", i, pos1[i]); 
            errlogPrintf("pos2[%d] = %.8f  ", i, pos2[i]); 
            errlogPrintf("vel[%d] = %.8f \n", i, vel[i]); 
        }

return 0;
}
