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
#include <mcs.h>
#include <mcssir.h>


/* 
 *  INPUTS:
 *      pcad->a = Choice of VE Algorithm            (STRING).
 *                FDE/HEAD_1/HEAD_2/HEAD_3/HEAD_4/
 *                HEADS_1_3/HEADS_2_4/HEADS_1_2/
 *                HEADS_3_4/ALL_HEADS
 *      pcad->b = Current debug level 0/1           (STRING).
 *
 *  OUTPUTS:
 *      pcad->vala = VE Algorithm to use            (LONG).
 *      pcad->valb = VE Heads to use                (LONG).
 *      pcad->valc = Command to send to PMAC        (STRING).
 *
 */

long azconfigCAD( struct cadRecord *pcad )
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
      strcpy( (char *)pcad->a, "ALL_HEADS");
      db_post_events( pcad, &pcad->a, 1 );
      ret = CAD_ACCEPT;
      break;

    case menuDirectivePRESET:
      error = check_string( pcad->a, str, MAX_STRING_SIZE, 1 );
      if( error == ALL_BLANKS )
      {
        sprintf( pcad->mess, "VE algorithm input field is blank");
        ret = CAD_REJECT;
      }
      else if( error == TOO_LONG )
      {
        sprintf( pcad->mess, "VE algorithm input field too long");
        ret = CAD_REJECT;
      }
      else if( !strcmp(str, "FDE") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to FDE\n" );
        *(long *)pcad->vala = MCS_FDE;
        *(long *)pcad->valb = MCS_NONE;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_FDE_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_1") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_1;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD1_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_2") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_2;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD2_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_3") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_3;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD3_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEAD_4") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to N and head to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_N;
        *(long *)pcad->valb = MCS_HEAD_4;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEAD4_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEADS_1_3") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to M&N and heads to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_M_N;
        *(long *)pcad->valb = MCS_HEADS_1_3;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEADS1_3_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEADS_2_4") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to M&N and heads to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_M_N;
        *(long *)pcad->valb = MCS_HEADS_2_4;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEADS2_4_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEADS_1_2") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to M&N and heads to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_M_N;
        *(long *)pcad->valb = MCS_HEADS_1_2;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEADS1_2_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "HEADS_3_4") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to M&N and heads to %ld\n",
                  *(long *)pcad->valb );
        *(long *)pcad->vala = MCS_M_N;
        *(long *)pcad->valb = MCS_HEADS_3_4;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_HEADS3_4_SETUP);
        ret = CAD_ACCEPT;
      }
      else if( !strcmp(str, "ALL_HEADS") )
      {
        if( debug )
          printf("azconfigCAD - PRESET: Setting algorithm to ALL_HEADS\n" );
        *(long *)pcad->vala = MCS_ALL_HEADS;
        *(long *)pcad->valb = MCS_ALL_AZHEADS;
        sprintf(pcad->valc, "wx$1300,$%x", MCS_ALL_HEADS_SETUP);
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
epicsRegisterFunction(azconfigCAD);
