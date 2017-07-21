#include <epicsStdlib.h>
#include <epicsStdioRedirect.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <string.h>
#include <iocsh.h> 
#include <math.h>
#include <time.h>
#include <epicsPrint.h>
#include <epicsTime.h>

#include <genSubRecord.h>
#include <menuCarstates.h>

#define TRANSFER_FILE_SIZE  512*1024  /* 0.5 MBytes */

char *buf;


void testLanInit( struct genSubRecord *pgsub )
{
  int  len;
  int  pos;
  int  space;
  char tempBuf[64];

  buf = malloc(TRANSFER_FILE_SIZE);
  pos = 0;
  for(;;)
  {
    sprintf(tempBuf, "Position in file of start of this line is: %d\n", pos);
    len   = strlen(tempBuf);
    pos  += len;
    space = TRANSFER_FILE_SIZE - pos - 1;
    if( space >= len )
      sprintf(buf+pos-len, "%s", tempBuf);
    else
      break;
  }
}


/* 
 *  pgsub->a = Name of File.
*/

long testLanProc( struct genSubRecord *pgsub )
{
  FILE          *fd;
  double        transRate;
  epicsTimeStamp startTime;           /* system time at start of task     */
  epicsTimeStamp currentTime;         /* system time right now            */
  double  numSecs = 1;                   /* time taken to execute task       */

  fd        = fopen(pgsub->a, "a");
  if( fd ) {
       epicsTimeGetCurrent(&startTime); 
       fwrite( buf, 1, TRANSFER_FILE_SIZE, fd);
       epicsTimeGetCurrent(&currentTime);
       fclose(fd);
       
       numSecs = epicsTimeDiffInSeconds(&currentTime, &startTime);
       transRate = TRANSFER_FILE_SIZE/(1024.0 * numSecs);

       *(long *)pgsub->vala = (long)transRate;
       *(long *)pgsub->valb = menuCarstatesIDLE;
  } else {  
     printf("testLanProc: Can not Open file: %s\n", (char *)pgsub->a);    
  } 

  return 0;
}
epicsRegisterFunction(testLanInit);
epicsRegisterFunction(testLanProc);
