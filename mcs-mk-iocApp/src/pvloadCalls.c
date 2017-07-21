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
#include <genSubRecord.h>
#include <mcssir.h>

void pvloadTask( int, int, int );
void pvloadSpawn( long, int, char *, long );
long pvload( char *, char *, int, int );

static char top[MAX_STRING_SIZE];
static char filepaths[MCS_NUM_FILES][DIRPATH_LEN];

static char cwFiles[4][16] =
  { "CWPOS1", "CWPOS2", "CWPOS3", "END" };


long setCWdemands( struct genSubRecord *pgsub )
{
  int  i;
  int  err;
  long debug;
  long file_id = 0;
  char dummy[MAX_STRING_SIZE];
  char dirpath[MAX_STRING_SIZE];

  i     = 0;
  err   = 0;
  debug = *(long *)pgsub->a;
  strcpy(dirpath, (char *)pgsub->b);
  strcpy(dummy, pgsub->name);
  sprintf(top, "top=%s:", (char *)strtok(dummy, ":"));
  while( strcmp(cwFiles[i], "END") )
  {
    if( !strcmp( (char *)pgsub->j, cwFiles[i] ) )
    {
      switch(i)
      {
        case 0:
          file_id = MCS_CW1_PAR;
          break;

        case 1:
          file_id = MCS_CW2_PAR;
          break;

        case 2:
          file_id = MCS_CW3_PAR;
          break;

        default:
          errlogPrintf("Invalid counterweight ID (%d)\n", i);
          err = 1;
          break;
      }
      break;
    }
    i++;
  }

  if( !err )
    pvloadSpawn(file_id, (int)top, dirpath, debug);

  if( debug )
    errlogPrintf("Leaving setCWdemands\n");

  return(0);
}


void loadPars( struct genSubRecord *pgsub )
{
  long debug;
  long  id = 0;
  char dummy[MAX_STRING_SIZE];
  char dirpath[MAX_STRING_SIZE];

  debug = *(long *)pgsub->a;
  strcpy(dirpath, pgsub->b);
  id    = *(long *)pgsub->c;

  strcpy(dummy, (char *)pgsub->name);
  sprintf(top, "top=%s:", (char *)strtok(dummy, ":"));

  pvloadSpawn(id, (int)top, dirpath, debug);
}


void pvloadSpawn( long file_id, int top, char *dirpath, long debug )
{
  int  error = 0;
  epicsThreadId id;
  char *str;

  strcpy(filepaths[0], dirpath);
  *filepaths[1] = '\0';
  *filepaths[2] = '\0';
  *filepaths[3] = '\0';
  *filepaths[4] = '\0';
  *filepaths[5] = '\0';

  switch( file_id )
  {
    case MCS_TELESCOPE_PAR:
#ifdef TELESCOPE
      str = strcat(filepaths[0], "/data/telescope.par");
#else
      str = strcat(filepaths[0], "/data/stage.par");
#endif
      break;

    case MCS_TAPEPOLYS_PAR:
      str = strcat(filepaths[0], "/data/tapePolys.par");
      break;

    case MCS_AXISLIMITS_PAR:
      str = strcat(filepaths[0], "/data/axisLimits.par");
      break;

    case MCS_SONY_PAR:
      str = strcat(filepaths[0], "/data/sony.par");
      break;

    case MCS_LOGDATA_PAR:
      str = strcat(filepaths[0], "/data/logData.par");
      break;

    case MCS_ALLFILES_PAR:
      strcpy(filepaths[4], dirpath);
#ifdef TELESCOPE
      str = strcat(filepaths[4], "/data/telescope.par");
#else
      str = strcat(filepaths[4], "/data/stage.par");
#endif
      str = strcat(filepaths[0], "/data/tapePolys.par");
      strcpy(filepaths[1], dirpath);
      str = strcat(filepaths[1], "/data/axisLimits.par");
      strcpy(filepaths[2], dirpath);
      str = strcat(filepaths[2], "/data/sony.par");
      strcpy(filepaths[3], dirpath);
      str = strcat(filepaths[3], "/data/logData.par");
      break;

    case MCS_CW1_PAR:
      str = strcat(filepaths[0], "/data/cwpos1.par");
      break;

    case MCS_CW2_PAR:
      str = strcat(filepaths[0], "/data/cwpos2.par");
      break;

    case MCS_CW3_PAR:
      str = strcat(filepaths[0], "/data/cwpos3.par");
      break;
   
    default:
      errlogPrintf("pvloadSpawn: invalid file_id (%ld)\n", file_id);
      error = 1;
      break;
  }

  if( !error ) {
    /* id = taskSpawn( "pvloadTask", 20, VX_FP_TASK, 20000, 
                    (FUNCPTR)pvloadTask, (int)top, (int)filepaths, (int)debug, 
                    0, 0, 0, 0, 0, 0, 0); */
     id = epicsThreadCreate ("pvloadTask", 
                                      20, 
				      0x2000,
                                      (EPICSTHREADFUNC)pvloadTask,
				     /*  (int)top, 
				      (int)filepaths, 
				      (int)debug, */ 
 				      NULL); 
    if (!id)
        errlogPrintf ("\nCannot create pv Load task!\n");
    }
}

 
void pvloadTask( int top, int buf, int debug )
{
  int  error;
  char (*cptr)[DIRPATH_LEN];

  cptr = (char (*)[DIRPATH_LEN])buf;
  while( *cptr[0] )
  {
    if( debug )
    {
      errlogPrintf("Before pvload...%s, %s)\n", *cptr, (char *)top);
      error = pvload( *cptr, (char *)top, 0, 0);
      errlogPrintf("error = %d, pvload( %s, %s)\n", error, *(cptr++), (char *)top);
    }
    else
      error = pvload( *(cptr++), (char *)top, 0, 0);
  }
}
epicsRegisterFunction(loadPars);
epicsRegisterFunction(setCWdemands);
