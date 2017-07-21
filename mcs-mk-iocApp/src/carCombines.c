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
#include <genSubRecord.h>
#include <menuCarstates.h>


/*  This routine is called from a "genSub" and passes the
 *  status and message values from one CAR into another.
 *
 *  INPUTS:
 *          pgsub->a:  The VAL  field from CAR 1.
 *          pgsub->b:  The OMSS field from CAR 1.
 *
 *  OUTPUTS:
 *          pgsub->vala: The output CAR value.
 *          pgsub->valb: The output CAR message.
 */

long carCombine1( struct genSubRecord *pgsub )
{
  *(long *)pgsub->vala = *(long *)pgsub->a;
  strncpy( pgsub->valb, pgsub->b, MAX_STRING_SIZE );
  
  return(0);
}


/*  This routine is called from a "genSub" and combines the
 *  status and message values from two CAR records.
 *
 *  INPUTS:
 *          pgsub->a:  The VAL  field from CAR 1.
 *          pgsub->b:  The OMSS field from CAR 1.
 *          pgsub->c:  The VAL  field from CAR 2.
 *          pgsub->d:  The OMSS field from CAR 2.
 *
 *  OUTPUTS:
 *          pgsub->vala: The resultant output CAR value.
 *          pgsub->valb: The resultant output CAR message.
 */

long carCombine2( struct genSubRecord *pgsub )
{
  long val1;
  long val2;
  long res;

  val1 = *((long *)(pgsub->a));
  val2 = *((long *)(pgsub->c));

  if (val1 > val2 ) res = val1; else res = val2;

  *((long *)(pgsub->vala)) = res;

  if( res == menuCarstatesERROR )
  {
    if( val1 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->b) );
    else
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->d) );
  }
  else
    strcpy( (char *)(pgsub->valb), " " );
  
  return(0);
}


/*  This routine is called from a "genSub" and combines the
 *  status and message values from three CAR records.
 *
 *  INPUTS:
 *          pgsub->a:  The VAL  field from CAR 1.
 *          pgsub->b:  The OMSS field from CAR 1.
 *          pgsub->c:  The VAL  field from CAR 2.
 *          pgsub->d:  The OMSS field from CAR 2.
 *          pgsub->e:  The VAL  field from CAR 3.
 *          pgsub->f:  The OMSS field from CAR 3.
 *
 *  OUTPUTS:
 *          pgsub->vala: The resultant output CAR value.
 *          pgsub->valb: The resultant output CAR message.
 */

long carCombine3( struct genSubRecord *pgsub )
{
  long val1;
  long val2;
  long val3;
  long res;

  val1 = *((long *)(pgsub->a));
  val2 = *((long *)(pgsub->c));
  val3 = *((long *)(pgsub->e));

  if (val1 > val2 ) res = val1; else res = val2;
  if (val3 > res ) res = val3; 
  
  *((long *)(pgsub->vala)) = res;

  if( res == menuCarstatesERROR )
  {
    if( val1 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->b) );
    else if( val2 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->d) );
    else
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->f) );
  }
  else
    strcpy( (char *)(pgsub->valb), " " );
  
  return(0);
}


/*  This routine is called from a "genSub" and combines the
 *  status and message values from four CAR records.
 *
 *  INPUTS:
 *          pgsub->a:  The VAL  field from CAR 1.
 *          pgsub->b:  The OMSS field from CAR 1.
 *          pgsub->c:  The VAL  field from CAR 2.
 *          pgsub->d:  The OMSS field from CAR 2.
 *          pgsub->e:  The VAL  field from CAR 3.
 *          pgsub->f:  The OMSS field from CAR 3.
 *          pgsub->g:  The VAL  field from CAR 4.
 *          pgsub->h:  The OMSS field from CAR 4.
 *
 *  OUTPUTS:
 *          pgsub->vala: The resultant output CAR value.
 *          pgsub->valb: The resultant output CAR message.
 */

long carCombine4( struct genSubRecord *pgsub )
{
  long val1;
  long val2;
  long val3;
  long val4;
  long res;
  long res1;
  long res2;

  val1 = *((long *)(pgsub->a));
  val2 = *((long *)(pgsub->c));
  val3 = *((long *)(pgsub->e));
  val4 = *((long *)(pgsub->g));

  if (val1 > val2 ) res1 = val1; else res1 = val2;
  if (val3 > val4 ) res2 = val3; else res2 = val4;
  if (res1 > res2 ) res  = res1; else res  = res2;

  *((long *)(pgsub->vala)) = res;

  if( res == menuCarstatesERROR )
  {
    if( val1 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->b) );
    else if( val2 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->d) );
    else if( val3 == menuCarstatesERROR )
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->f) );
    else
      strcpy( (char *)(pgsub->valb), (char *)(pgsub->h) );
  }
  else
    strcpy( (char *)(pgsub->valb), " " );
  
  return(0);
}
epicsRegisterFunction(carCombine1);
epicsRegisterFunction(carCombine2);
epicsRegisterFunction(carCombine3);
epicsRegisterFunction(carCombine4);
