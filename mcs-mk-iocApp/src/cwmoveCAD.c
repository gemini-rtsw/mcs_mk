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
#include <mcs.h>


#define MASK_MOVE   31
#define MASK_NOMOVE 16

/* 
 *  INPUTS:
 *      pcad->a = Axial 1 demand           STRING -> DOUBLE
 *      pcad->b = Axial 2 demand           STRING -> DOUBLE
 *      pcad->c = Cross-axial 1 demand     STRING -> DOUBLE
 *      pcad->d = Cross-axial 2 demand     STRING -> DOUBLE
 *      pcad->e = Debug State 0/1          STRING -> LONG
 *      pcad->f = Upper limit of travel    STRING -> DOUBLE
 *      pcad->g = Lower limit of travel    STRING -> DOUBLE
 *      pcad->h = Axial 1 current          STRING -> DOUBLE
 *      pcad->i = Axial 2 current          STRING -> DOUBLE
 *      pcad->j = Cross-axial 1 current    STRING -> DOUBLE
 *      pcad->k = Cross-axial 2 current    STRING -> DOUBLE
 *
 *  OUTPUTS:
 *      pcad->vala = Axial 1 demand                      (DOUBLE).
 *      pcad->valb = Axial 1 sequence mask               (LONG).
 *      pcad->valc = Axial 2 demand                      (DOUBLE).
 *      pcad->vald = Axial 2 sequence mask               (LONG).
 *      pcad->vale = Cross-axial 1 demand                (DOUBLE).
 *      pcad->valf = Cross-axial 1 sequence mask         (LONG).
 *      pcad->valg = Cross-axial 2 demand                (DOUBLE).
 *      pcad->valh = Cross-axial 2 sequence mask         (LONG).
 *
 */

long cwmoveCAD( struct cadRecord *pcad )
{
  long   ret = 0;
  long   moveAx1;
  long   moveAx2;
  long   moveCax1;
  long   moveCax2;
  long   error;
  long   debug;
  double ax1D = 0;
  double ax2D = 0;
  double cax1D = 0;
  double cax2D = 0;
  double ax1C;
  double ax2C;
  double cax1C;
  double cax2C;
  double upperL;
  double lowerL;

  debug  = atol( (char *)pcad->e );
  upperL = strtod( pcad->f, NULL );
  lowerL = strtod( pcad->g, NULL );
  ax1C   = strtod( pcad->h, NULL );
  ax2C   = strtod( pcad->i, NULL );
  cax1C  = strtod( pcad->j, NULL );
  cax2C  = strtod( pcad->k, NULL );

  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
      strcpy( (char *)pcad->a, " ");
      db_post_events( pcad, &pcad->a, 1 );
      strcpy( (char *)pcad->b, " ");
      db_post_events( pcad, &pcad->b, 1 );
      strcpy( (char *)pcad->c, " ");
      db_post_events( pcad, &pcad->c, 1 );
      strcpy( (char *)pcad->d, " ");
      db_post_events( pcad, &pcad->d, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      /* Axial 1 */
      error = check_numeric( pcad->a );
      if( debug )
        printf("cwmoveCAD: error = %ld from check_numeric for axial 1\n", error);
      if( error )
      {
        moveAx1 = 0;
        if( error == ALL_BLANKS )  /* Move to same position */
          ret = CAD_ACCEPT;
        else
        {
          sprintf(pcad->mess, "Axial 1 demand invalid");
          ret = CAD_REJECT;
        }
      }
      else
        moveAx1 = 1;

      /* We do have to move Ax1 */

      if( moveAx1 )
      {
        ax1D = strtod( pcad->a, NULL );
        if( debug )
          printf("cwmoveCAD: ax1D = %f, lower Limit = %f, upper Limit = %f\n", 
                    ax1D, lowerL, upperL);
        if( ax1D < lowerL )
        {
          sprintf(pcad->mess, "Ax1 demand %6.3f below limit (%6.3f)", ax1D, lowerL);
          ret = CAD_REJECT;
        }
        else if( ax1D > upperL )
        {
          sprintf(pcad->mess, "Ax1 demand %6.3f above limit (%6.3f)", ax1D, upperL);
          ret = CAD_REJECT;
        }
        else
          ret = CAD_ACCEPT;
      }

      /* Axial 2 */
      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->b );
        if( debug )
          printf("cwmoveCAD: error = %ld from check_numeric for axial 2\n", error);
        if( error )
        {
          moveAx2 = 0;
          if( error == ALL_BLANKS )  /* Move to same position */
            ret = CAD_ACCEPT;
          else
          {
            sprintf(pcad->mess, "Axial 2 demand invalid");
            ret = CAD_REJECT;
          }
        }
        else
          moveAx2 = 1;

        /* We do have to move the counterweight */

        if( moveAx2 )
        {
          ax2D = strtod( pcad->b, NULL );
          if( debug )
            printf("cwmoveCAD: ax2D = %f, lower Limit = %f, upper Limit = %f\n", 
                    ax2D, lowerL, upperL);
          if( ax2D < lowerL )
          {
            sprintf(pcad->mess, "Ax2 demand %6.3f below limit (%6.3f)", ax2D, lowerL);
            ret = CAD_REJECT;
          }
          else if( ax2D > upperL )
          {
            sprintf(pcad->mess, "Ax2 demand %6.3f above limit (%6.3f)", ax2D, upperL);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      /* Cross-axial 1 */
      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->c );
        if( debug )
          printf("cwmoveCAD: error = %ld from check_numeric for cross-axial 1\n", error);
        if( error )
        {
          moveCax1 = 0;
          if( error == ALL_BLANKS )  /* Move to same position */
            ret = CAD_ACCEPT;
          else
          {
            sprintf(pcad->mess, "Cross-axial 1 demand invalid");
            ret = CAD_REJECT;
          }
        }
        else
          moveCax1 = 1;

        /* We do have to move the counterweight */

        if( moveCax1 )
        {
          cax1D = strtod( pcad->c, NULL );
          if( debug )
            printf("cwmoveCAD: cax1D = %f, lower Limit = %f, upper Limit = %f\n", 
                    cax1D, lowerL, upperL);
          if( cax1D < lowerL )
          {
            sprintf(pcad->mess, "Cax1 demand %6.3f below limit (%6.3f)", cax1D, lowerL);
            ret = CAD_REJECT;
          }
          else if( cax1D > upperL )
          {
            sprintf(pcad->mess, "Cax1 demand %6.3f above limit (%6.3f)", cax1D, upperL);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      /* Cross-axial 2 */
      if( ret == CAD_ACCEPT )
      {
        error = check_numeric( pcad->d );
        if( debug )
          printf("cwmoveCAD: error = %ld from check_numeric for cross-axial 2\n", error);
        if( error )
        {
          moveCax2 = 0;
          if( error == ALL_BLANKS )  /* Move to same position */
            ret = CAD_ACCEPT;
          else
          {
            sprintf(pcad->mess, "Cross-axial 2 demand invalid");
            ret = CAD_REJECT;
          }
        }
        else
          moveCax2 = 1;

        /* We do have to move the counterweight */

        if( moveCax2 )
        {
          cax2D = strtod( pcad->d, NULL );
          if( debug )
            printf("cwmoveCAD: cax2D = %f, lower Limit = %f, upper Limit = %f\n", 
                    cax2D, lowerL, upperL);
          if( cax2D < lowerL )
          {
            sprintf(pcad->mess, "Cax2 demand %6.3f below limit (%6.3f)", cax2D, lowerL);
            ret = CAD_REJECT;
          }
          else if( cax2D > upperL )
          {
            sprintf(pcad->mess, "Cax2 demand %6.3f above limit (%6.3f)", cax2D, upperL);
            ret = CAD_REJECT;
          }
          else
            ret = CAD_ACCEPT;
        }
      }

      if( ret == CAD_ACCEPT )
      {
        if( moveAx1 && moveAx2 && moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( moveAx1 && moveAx2 && moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( moveAx1 && moveAx2 && !moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( moveAx1 && !moveAx2 && moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( !moveAx1 && moveAx2 && moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( moveAx1 && moveAx2 && !moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( moveAx1 && !moveAx2 && !moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( !moveAx1 && !moveAx2 && moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( moveAx1 && !moveAx2 && !moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( !moveAx1 && moveAx2 && !moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( !moveAx1 && !moveAx2 && moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( !moveAx1 && !moveAx2 && !moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( !moveAx1 && !moveAx2 && !moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( !moveAx1 && moveAx2 && !moveCax1 && moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1C;
          *(long *)pcad->valf   = MASK_NOMOVE;
          *(double *)pcad->valg = cax2D;
          *(long *)pcad->valh   = MASK_MOVE;
        }
        else if( moveAx1 && !moveAx2 && moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1D;
          *(long *)pcad->valb   = MASK_MOVE;
          *(double *)pcad->valc = ax2C;
          *(long *)pcad->vald   = MASK_NOMOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
        }
        else if( !moveAx1 && moveAx2 && moveCax1 && !moveCax2 )
        {
          *(double *)pcad->vala = ax1C;
          *(long *)pcad->valb   = MASK_NOMOVE;
          *(double *)pcad->valc = ax2D;
          *(long *)pcad->vald   = MASK_MOVE;
          *(double *)pcad->vale = cax1D;
          *(long *)pcad->valf   = MASK_MOVE;
          *(double *)pcad->valg = cax2C;
          *(long *)pcad->valh   = MASK_NOMOVE;
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
epicsRegisterFunction(cwmoveCAD);
