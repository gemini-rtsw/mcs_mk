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


/* 
 *  INPUTS:
 *      pcad->a = Choice of VE Algorithm            (STRING).
 *                FDE/HEAD_1/HEAD_2/HEADS_1_2/FULL/
 *                HEAD_1_T/HEAD_2_T
 *      pcad->b = Current debug level 0/1           (STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = VE Algorithm to use            (LONG).
 *      pcad->valb = VE Heads to use                (LONG).
 *      pcad->valc = Command to send to PMAC        (STRING).
 *
 */

long elconfigCAD( struct cadRecord *pcad )
{
  long ret = 0;
  long debug;
  char str[MAX_STRING_SIZE];
  long error;

  debug = atol( (char *)pcad->b );
  switch( pcad->dir )
  {
    case menuDirectiveMARK:
      ret = CAD_ACCEPT;
      break;

    case menuDirectiveCLEAR:
/*
 *  Set default value on CLEAR.
 */
      strcpy( (char *)pcad->a, "FULL");
      db_post_events( pcad, &pcad->a, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "VE algorithm field is blank" );
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "VE algorithm field too long" );
        ret = CAD_REJECT;
      }
      else if( !strcmp(str, "FDE") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to FDE\n" );
        *(long *)pcad->vala = MCS_FDE;
        *(long *)pcad->valb = MCS_NONE;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_FDE_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_1") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_1;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD1_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_2") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_2;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD2_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEADS_1_2") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to M&N and heads to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_M_N;
        *(long *)pcad->valb = MCS_HEADS_1_2;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEADS1_2_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "FULL") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to FULL\n" );
        *(long *)pcad->vala = MCS_ALL_HEADS;
        *(long *)pcad->valb = MCS_ALL_ELHEADS;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_ALL_HEADS_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_1_T") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to EL_N\n" );
        *(long *)pcad->vala = MCS_EL_N;
        *(long *)pcad->valb = MCS_HEAD_1_T;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD1T_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_2_T") )
      {
        if( debug )
          printf("elconfigCAD - PRESET: Setting algorithm to EL_N\n" );
        *(long *)pcad->vala = MCS_EL_N;
        *(long *)pcad->valb = MCS_HEAD_2_T;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD2T_SETUP);
        ret = CAD_ACCEPT;
      }
      else
      {
        sprintf( pcad->mess, "%s: Not a valid VE algorithm", str );
        ret = CAD_REJECT;
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
epicsRegisterFunction(elconfigCAD);
