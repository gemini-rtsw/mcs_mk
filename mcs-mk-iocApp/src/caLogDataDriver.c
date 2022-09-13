#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cadef.h>
#include <db_access.h>
#include <epicsThread.h>
#include <epicsEvent.h>
#include <epicsExport.h>
#include <epicsPrint.h>
#include <iocsh.h>

#include "caLogDataDriver.h"
/* 
   Note that even though this is a Channel Access task, there are
   no calls to ca_pend_io. These are not required because this task
   runs in the same IOC as the database, therefore CA calls default
   to local DB calls and no network delays are involved.
*/

#define CALOGDATA_PRI 45  /* Priority of the caLogData task */

int caLogDataDriverDebug = 0;

char mbbiStates[MAX_MENU_ENTRIES][FIELD_SIZE] =
{ "ZRST", "ONST", "TWST", "THST", "FRST", "FVST", "SXST", "SVST",
  "EIST", "NIST", "TEST", "ELST", "TVST", "TTST", "FTST", "FFST" };

char dataset1L[MAX_NUM_LOGGED][STATE_FIELD_SIZE];
char dataset1T[MAX_NUM_LOGGED][TYPE_SIZE];
char dataset1A[MAX_NUM_LOGGED][FIELD_SIZE];
char dataset1C[MAX_NUM_LOGGED][FIELD_SIZE];

char dataset2L[MAX_NUM_LOGGED][STATE_FIELD_SIZE];
char dataset2T[MAX_NUM_LOGGED][TYPE_SIZE];
char dataset2A[MAX_NUM_LOGGED][FIELD_SIZE];
char dataset2C[MAX_NUM_LOGGED][FIELD_SIZE];

char dataset3L[MAX_NUM_LOGGED][STATE_FIELD_SIZE];
char dataset3T[MAX_NUM_LOGGED][TYPE_SIZE];
char dataset3A[MAX_NUM_LOGGED][FIELD_SIZE];
char dataset3C[MAX_NUM_LOGGED][FIELD_SIZE];

char dataset4L[MAX_NUM_LOGGED][STATE_FIELD_SIZE];
char dataset4T[MAX_NUM_LOGGED][TYPE_SIZE];
char dataset4A[MAX_NUM_LOGGED][FIELD_SIZE];
char dataset4C[MAX_NUM_LOGGED][FIELD_SIZE];

char azMenuEntry[MAX_MENU_ENTRIES][MAX_STRING_SIZE];
char azPmacAddr[MAX_MENU_ENTRIES][MAX_STRING_SIZE];  /* Holds full address with type */
char azStrType[MAX_MENU_ENTRIES][TYPE_SIZE];
char azStrAddr[MAX_MENU_ENTRIES][FIELD_SIZE];        /* Holds the 4 hex digits */
char elMenuEntry[MAX_MENU_ENTRIES][MAX_STRING_SIZE];
char elPmacAddr[MAX_MENU_ENTRIES][MAX_STRING_SIZE];  /* Holds full address with type */
char elStrType[MAX_MENU_ENTRIES][TYPE_SIZE];
char elStrAddr[MAX_MENU_ENTRIES][FIELD_SIZE];        /* Holds the 4 hex digits */
char cwMenuEntry[MAX_MENU_ENTRIES][MAX_STRING_SIZE];
char cwPmacAddr[MAX_MENU_ENTRIES][MAX_STRING_SIZE];  /* Holds full address with type */
char cwStrType[MAX_MENU_ENTRIES][TYPE_SIZE];
char cwStrAddr[MAX_MENU_ENTRIES][FIELD_SIZE];        /* Holds the 4 hex digits */

char   az[3];
char   el[3];
char   cw[3];
//SEM_ID caLogDataSem;
epicsEventId  caLogDataSem;

//int    caLogDataID;
epicsThreadId    caLogDataID;
long   azFlagLocal;
long   elFlagLocal;
long   cwFlagLocal;
int    total;
int    index1 = 0;
int    index2 = 0;
int    index3 = 0;
int    index4 = 0;
char   header1[HEADER_SIZE];
char   header2[HEADER_SIZE];
char   menuCard[FIELD_SIZE];
char   menuLabel[STATE_FIELD_SIZE];
char   menuType[TYPE_SIZE];
char   menuAddress[FIELD_SIZE];
int    azCount;
int    elCount;
int    cwCount;
int    command;
int    totSources;
int    busy_flag;


void caInitLogSetup( char *top, char *azstr, char *elstr, char *cwstr )
{
  int  i;
  int  j;
  chid id;
  char buf[MAX_STRING_SIZE];
  int  num;

  //ca_task_initialize();
  /* Create ca context with preemptive callback enabled -- Now required in EPICS 3.14 */
  SEVCHK(ca_context_create(ca_enable_preemptive_callback), "caInitLogSetup() calling ca_context_create()");

  strcpy(az, azstr);
  strcpy(el, elstr);
  strcpy(cw, cwstr);
  

  /* Az */

  /* Get the channel ID's for the string records which hold the menu entries */


  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    sprintf(buf, "%s%sMenuEntry%d", top, az, i);


    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, azMenuEntry[i] );
    if(caLogDataDriverDebug) epicsPrintf("caInitLogSetup(): %s = %s\n", buf, azMenuEntry[i]);

    sprintf(buf, "%s%sPmacAddr%d", top, az, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, azPmacAddr[i] );
    if(caLogDataDriverDebug) epicsPrintf("caInitLogSetup(): %s = %s\n", buf, azPmacAddr[i]);
  }
 
  /* Get the channel ID's for the state fields of the MBBI records which will hold
     the menus and write the menu entries */

  for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
  {
    for(j=0; j<MAX_MENU_ENTRIES; j++)
    {
      sprintf(buf, "%slogData%sChoice%d.%s", top, az, i, mbbiStates[j]);
      SEVCHK( ca_search(buf, &id), "ca_search failed\n");
      if( !strcmp( azMenuEntry[j], "END" ) )
        break;
      else
        ca_put( DBR_STRING, id, azMenuEntry[j] );
    }
   
    /* Make the MBBI records perform special processing so that these new
       menu entries are recognised */

    sprintf(buf, "%slogData%sChoice%d.ZRVL", top, az, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_put( DBR_LONG, id, 0 );
  }

  /* Build up three lists for each Dataset: Label, Data Type, Hex Address */

  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    decodeAddress( azPmacAddr[i], &num, azStrType[i], azStrAddr[i] );
    construct_dataset( num, azMenuEntry[i], azStrType[i], azStrAddr[i], az );
  }

  /* El */

  /* Get the channel ID's for the string records which hold the menu entries */

  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    sprintf(buf, "%s%sMenuEntry%d", top, el, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, elMenuEntry[i] );

    sprintf(buf, "%s%sPmacAddr%d", top, el, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, elPmacAddr[i] );
  }
 
  /* Get the channel ID's for the state fields of the MBBI records which will hold
     the menus and write the menu entries */

  for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
  {
    for(j=0; j<MAX_MENU_ENTRIES; j++)
    {
      sprintf(buf, "%slogData%sChoice%d.%s", top, el, i, mbbiStates[j]);
      SEVCHK( ca_search(buf, &id), "ca_search failed\n");
      if( !strcmp( elMenuEntry[j], "END" ) )
        break;
      else
        ca_put( DBR_STRING, id, elMenuEntry[j] );
    }

    /* Make the MBBI records perform special processing so that these new
       menu entries are recognised */

    sprintf(buf, "%slogData%sChoice%d.ZRVL", top, el, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_put( DBR_LONG, id, 0 );
  }

  /* Build up two lists for each Dataset: Type, Hex Address */

  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    decodeAddress( elPmacAddr[i], &num, elStrType[i], elStrAddr[i] );
    construct_dataset( num, elMenuEntry[i], elStrType[i], elStrAddr[i], el );
  }

  /* Cw */

  /* Get the channel ID's for the string records which hold the menu entries */

  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    sprintf(buf, "%s%sMenuEntry%d", top, cw, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, cwMenuEntry[i] );

    sprintf(buf, "%s%sPmacAddr%d", top, cw, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_get( DBR_STRING, id, cwPmacAddr[i] );
  }
 
  /* Get the channel ID's for the state fields of the MBBI records which will hold
     the menus and write the menu entries */

  for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
  {
    for(j=0; j<MAX_MENU_ENTRIES; j++)
    {
      sprintf(buf, "%slogData%sChoice%d.%s", top, cw, i, mbbiStates[j]);
      SEVCHK( ca_search(buf, &id), "ca_search failed\n");
      if( !strcmp( cwMenuEntry[j], "END" ) )
        break;
      else
        ca_put( DBR_STRING, id, cwMenuEntry[j] );
    }

    /* Make the MBBI records perform special processing so that these new
       menu entries are recognised */

    sprintf(buf, "%slogData%sChoice%d.ZRVL", top, cw, i);
    SEVCHK( ca_search(buf, &id), "ca_search failed\n");
    ca_put( DBR_LONG, id, 0 );
  }

  /* Build up two lists for each Dataset: Type, Hex Address */

  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    decodeAddress( cwPmacAddr[i], &num, cwStrType[i], cwStrAddr[i] );
    construct_dataset( num, cwMenuEntry[i], cwStrType[i], cwStrAddr[i], cw );
  }

  if(caLogDataDriverDebug) {
     for( i=0; i<index1; i++ )
       epicsPrintf( "Dataset1[%d]: Label = %s, Type = %s, Address = %s\n", 
                i, dataset1L[i], dataset1T[i], dataset1A[i] );

     for( i=0; i<index2; i++ )
       epicsPrintf( "Dataset2[%d]: Label = %s, Type = %s, Address = %s\n", 
                i, dataset2L[i], dataset2T[i], dataset2A[i] );

     for( i=0; i<index3; i++ )
       epicsPrintf( "Dataset3[%d]:  Label = %s, Type = %s, Address = %s\n", 
                i, dataset3L[i], dataset3T[i], dataset3A[i] );
   }


  caLogDataSem = epicsEventMustCreate(epicsEventEmpty);
  if( !caLogDataSem )
    printf("Creating caLogDataSem failed\n");
  else
    caLogDataID = epicsThreadCreate("caLogDataTask", CALOGDATA_PRI, epicsThreadGetStackSize(epicsThreadStackMedium),
                       (EPICSTHREADFUNC)caLogDataTask, (void *)top);
}


void  caLogDataTask(void *parm)
{
  char *top=(char *)parm;

  chid azMenu[LAST_LOG_SOURCE];
  chid azType[LAST_LOG_SOURCE];
  chid azSwitch[LAST_LOG_SOURCE];
  chid azAddress[LAST_LOG_SOURCE];
  chid elMenu[LAST_LOG_SOURCE];
  chid elType[LAST_LOG_SOURCE];
  chid elSwitch[LAST_LOG_SOURCE];
  chid elAddress[LAST_LOG_SOURCE];
  chid cwMenu[LAST_LOG_SOURCE];
  chid cwType[LAST_LOG_SOURCE];
  chid cwSwitch[LAST_LOG_SOURCE];
  chid cwAddress[LAST_LOG_SOURCE];
  char buf[MAX_STRING_SIZE];
  char addrRet[MAX_STRING_SIZE];
  int  i;
  int  j;
  int  close;
  int  error;
  chid *ptrMenu;
  chid *ptrType;
  chid *ptrSwitch;
  chid *ptrAddress;
  char *pheader;
  int  dataID;
  char type[3];
  char addr[5];
  char *axis;
  long *ptrFlag;

  //ca_task_initialize();
  SEVCHK(ca_context_create(ca_enable_preemptive_callback), "caInitLogSetup() calling ca_context_create()");

  /* Get all of the Channel ID's we will need */

  for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
  {
    sprintf(buf, "%slogData%sChoice%d", top, az, i);
    SEVCHK( ca_search(buf, &azMenu[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sChoice%d", top, el, i);
    SEVCHK( ca_search(buf, &elMenu[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sChoice%d", top, cw, i);
    SEVCHK( ca_search(buf, &cwMenu[i]), "ca_search failed\n");

    sprintf(buf, "%slogData%sConfigType%d", top, az, i);
    SEVCHK( ca_search(buf, &azType[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sConfigType%d", top, el, i);
    SEVCHK( ca_search(buf, &elType[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sConfigType%d", top, cw, i);
    SEVCHK( ca_search(buf, &cwType[i]), "ca_search failed\n");

    sprintf(buf, "%slogData%sSwitch%d", top, az, i);
    SEVCHK( ca_search(buf, &azSwitch[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sSwitch%d", top, el, i);
    SEVCHK( ca_search(buf, &elSwitch[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sSwitch%d", top, cw, i);
    SEVCHK( ca_search(buf, &cwSwitch[i]), "ca_search failed\n");

    sprintf(buf, "%slogData%sValue%d.C", top, az, i);
    SEVCHK( ca_search(buf, &azAddress[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sValue%d.C", top, el, i);
    SEVCHK( ca_search(buf, &elAddress[i]), "ca_search failed\n");
    sprintf(buf, "%slogData%sValue%d.C", top, cw, i);
    SEVCHK( ca_search(buf, &cwAddress[i]), "ca_search failed\n");
  }

  for(;;)
  {
      epicsEventMustWait(caLogDataSem);
    
      switch(command)
      {
        case READ_CHANNELS:
          total       = 0;
          azFlagLocal = 0;
          elFlagLocal = 0;
          cwFlagLocal = 0;

          for(j=0; j<3; j++)
          {
            if( j==0 )
            {
              axis       = az;
              ptrMenu    = azMenu;
              ptrType    = azType;
              ptrSwitch  = azSwitch;
              ptrAddress = azAddress;
              ptrFlag    = &azFlagLocal;
            }
            else if( j==1 )
            {
              axis       = el;
              ptrMenu    = elMenu;
              ptrType    = elType;
              ptrSwitch  = elSwitch;
              ptrAddress = elAddress;
              ptrFlag    = &elFlagLocal;
            }
            else if( j==2 )
            {
              axis       = cw;
              ptrMenu    = cwMenu;
              ptrType    = cwType;
              ptrSwitch  = cwSwitch;
              ptrAddress = cwAddress;
              ptrFlag    = &cwFlagLocal;
            }

            for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
            {
              /* First check if a name has been selected */
              /* If so, set up the screen with ca_puts */
              SEVCHK( ca_get(DBR_STRING, ptrMenu[i], buf), "ca_get failed\n");
              if( strncmp(buf, "NONE", 4) )
              {
                error = getAddress( axis, buf, addrRet );
                if( !error )
                {
                  decodeAddress( addrRet, &dataID, type, addr );
                  SEVCHK( ca_put(DBR_STRING, ptrType[i], type), "ca_put failed\n");
                  SEVCHK( ca_put(DBR_STRING, ptrAddress[i], addr), "ca_put failed\n");
                  SEVCHK( ca_put(DBR_STRING, ptrSwitch[i], "YES"), "ca_put failed\n");
                  total++;
                  *ptrFlag = 1;
                }
              }
              else    
              {
                SEVCHK( ca_get(DBR_STRING, ptrSwitch[i], buf), "ca_get failed\n");
                if( !strncmp(buf, "YES", 3) )
                {
                  total++;
                  *ptrFlag = 1;
                }
              }
            }
          }
          busy_flag = 0;
          break;

        case WRITE_CHANNELS:
          if( !strcmp(menuCard, az) )
          {
            SEVCHK( ca_put(DBR_STRING, azMenu[azCount], menuLabel), 
                   "ca_put failed (Az Label)\n");
            SEVCHK( ca_put(DBR_STRING, azType[azCount], menuType), 
                   "ca_put failed (Az Type)\n");
            SEVCHK( ca_put(DBR_STRING, azSwitch[azCount], "YES"), 
                   "ca_put failed (Az Switch)\n");
            SEVCHK( ca_put(DBR_STRING, azAddress[azCount], menuAddress), 
                   "ca_put failed (Az Address)\n");
          }
          else if( !strcmp(menuCard, el) )
          {
            SEVCHK( ca_put(DBR_STRING, elMenu[elCount], menuLabel),
                   "ca_put failed (El Label)\n");
            SEVCHK( ca_put(DBR_STRING, elType[elCount], menuType),
                   "ca_put failed (El Type)\n");
            SEVCHK( ca_put(DBR_STRING, elSwitch[elCount], "YES"),
                   "ca_put failed (El Switch)\n");
            SEVCHK( ca_put(DBR_STRING, elAddress[elCount], menuAddress),
                   "ca_put failed (El Address)\n");
          }
          else if( !strcmp(menuCard, cw) )
          {
            SEVCHK( ca_put(DBR_STRING, cwMenu[cwCount], menuLabel),
                   "ca_put failed (Cw Label)\n");
            SEVCHK( ca_put(DBR_STRING, cwType[cwCount], menuType),
                   "ca_put failed (Cw Type)\n");
            SEVCHK( ca_put(DBR_STRING, cwSwitch[cwCount], "YES"),
                   "ca_put failed (Cw Switch)\n");
            SEVCHK( ca_put(DBR_STRING, cwAddress[cwCount], menuAddress),
                   "ca_put failed (Cw Address)\n");
          }
          busy_flag = 0;
          break;

        case READ_HEADER:
          header2[0]  = '\0';
          pheader     = header2;
          strcpy(pheader, "SERVO COUNTER ");
          totSources = 1;
          if( !strcmp(menuCard, az) )
          {
            ptrMenu    = azMenu;
            ptrType    = azType;
            ptrSwitch  = azSwitch;
            ptrAddress = azAddress;
          }
          else if( !strcmp(menuCard, el) )
          {
            ptrMenu    = elMenu;
            ptrType    = elType;
            ptrSwitch  = elSwitch;
            ptrAddress = elAddress;
          }
          else if( !strcmp(menuCard, cw) )
          {
            ptrMenu    = cwMenu;
            ptrType    = cwType;
            ptrSwitch  = cwSwitch;
            ptrAddress = cwAddress;
          }
          else
          {
             epicsPrintf("caLogDataTask(): READ_HEADER: bad menuCard %s\n", menuCard);
             return;
          }

          for(i=FIRST_LOG_SOURCE; i<LAST_LOG_SOURCE; i++)
          {
            SEVCHK( ca_get(DBR_STRING, ptrSwitch[i], buf), "ca_get failed\n");
            if( !strncmp(buf, "YES", 3) )
            {
              totSources++;
              close = 0;
              SEVCHK( ca_get(DBR_STRING, ptrMenu[i], buf), "ca_get failed\n");
              if( strncmp(buf, "NONE", 4) )
              {
                strncat(pheader, buf, strlen(buf));
                strncat(pheader, "(", 1);
                close = 1;
              }
              SEVCHK( ca_get(DBR_STRING, ptrType[i], buf), "ca_get failed\n");
              strncat(pheader,  buf, 2);
              strncat(pheader, ":$", 2);
              SEVCHK( ca_get(DBR_STRING, ptrAddress[i], buf), "ca_get failed\n");
              strncat(pheader, buf, 4);
              if( close )
                strncat(pheader, ")  ", 3);
              else
                strncat(pheader, "   ", 3);
            }
          }
          strncat(pheader, "\n", 1);
          busy_flag = 0;
          break;

        case SWITCH_OFF:
          for(i=azCount; i<LAST_LOG_SOURCE; i++)
            SEVCHK( ca_put(DBR_STRING, azSwitch[i], "NO"), "ca_put failed\n");
          for(i=elCount; i<LAST_LOG_SOURCE; i++)
            SEVCHK( ca_put(DBR_STRING, elSwitch[i], "NO"), "ca_put failed\n");
          for(i=cwCount; i<LAST_LOG_SOURCE; i++)
            SEVCHK( ca_put(DBR_STRING, cwSwitch[i], "NO"), "ca_put failed\n");
          busy_flag = 0;
          break;

        default:
          break;
      }
    
  }
}


void caReadLogSetup( long *azFlag, long *elFlag, long *cwFlag )
{
  command   = READ_CHANNELS;
  busy_flag = 1;
  //semGive(caLogDataSem);
  epicsEventSignal(caLogDataSem);
  while( busy_flag )
    //taskDelay(2);
    epicsThreadSleep(0.025);  // wait for 2 80 Hz clock ticks

  *azFlag = azFlagLocal;
  *elFlag = elFlagLocal;
  *cwFlag = cwFlagLocal;
}


void caWriteLogSetup( char *dataset )
{
  char (*ptrL)[STATE_FIELD_SIZE];
  char (*ptrT)[TYPE_SIZE];
  char (*ptrA)[FIELD_SIZE];
  char (*ptrC)[FIELD_SIZE];
  int  loop;
  int  i;

  if( !strcmp(dataset, "DATASET1") )
  {
    ptrL = dataset1L;
    ptrT = dataset1T;
    ptrA = dataset1A;
    ptrC = dataset1C;
    loop = index1;
  }
  else if( !strcmp(dataset, "DATASET2") )
  {
    ptrL = dataset2L;
    ptrT = dataset2T;
    ptrA = dataset2A;
    ptrC = dataset2C;
    loop = index2;
  }
  else if( !strcmp(dataset, "DATASET3") )
  {
    ptrL = dataset3L;
    ptrT = dataset3T;
    ptrA = dataset3A;
    ptrC = dataset3C;
    loop = index3;
  }
  else if( !strcmp(dataset, "DATASET4") )
  {
    ptrL = dataset4L;
    ptrT = dataset4T;
    ptrA = dataset4A;
    ptrC = dataset4C;
    loop = index4;
  }
  else 
  {
     epicsPrintf("caWriteLogSetup: bad dataset name %s\n", dataset);
     return;
  }

  command = WRITE_CHANNELS;
  azCount = FIRST_LOG_SOURCE;
  elCount = FIRST_LOG_SOURCE;
  cwCount = FIRST_LOG_SOURCE;

  for(i=0; i<loop; i++)
  {
    strcpy(menuLabel,   ptrL[i]);
    strcpy(menuType,    ptrT[i]);
    strcpy(menuAddress, ptrA[i]);

    if( !strcmp(ptrC[i], az) )
      strcpy(menuCard, az);
    else if( !strcmp(ptrC[i], el) )
      strcpy(menuCard, el);
    else if( !strcmp(ptrC[i], cw) )
      strcpy(menuCard, cw);

    busy_flag = 1;
   // semGive(caLogDataSem);
    epicsEventSignal(caLogDataSem);
    while( busy_flag )
      //taskDelay(2);
      epicsThreadSleep(0.025);  // wait for 2 80 Hz clock ticks

    if( !strcmp(ptrC[i], az) )
      azCount++;
    else if( !strcmp(ptrC[i], el) )
      elCount++;
    else if( !strcmp(ptrC[i], cw) )
      cwCount++;
  }

  /* Make sure remaining sources have their switches set to OFF */

  command   = SWITCH_OFF;
  busy_flag = 1;
  //semGive(caLogDataSem);
  epicsEventSignal(caLogDataSem);
  while( busy_flag )
    //taskDelay(2);
    epicsThreadSleep(0.025);  // wait for 2 80 Hz clock ticks
}


void caReadHeader( char *card, char *head )
{
  strcpy(menuCard, card);
  command   = READ_HEADER;
  busy_flag = 1;
  epicsEventSignal(caLogDataSem);
  while( busy_flag )
    epicsThreadSleep(0.025);  // wait for 2 80 Hz clock ticks

  sprintf(header1, "%d ", totSources);
  strcat(header1, header2);
  strcpy(head, header1);
  if(caLogDataDriverDebug) epicsPrintf("caReadHeader:\n%s\n", head);
}


int getAddress( char *card, char *name, char *address )
{
  int i;
  int ret;

  ret = 1;
  for(i=0; i<MAX_MENU_ENTRIES; i++)
  {
    if( !strcmp(card, az) )
    {
      if( !strcmp(name, azMenuEntry[i]) )
      {
        strcpy(address, azPmacAddr[i]);
        ret = 0;
        break;
      }
    }
    else if( !strcmp(card, el) )
    {
      if( !strcmp(name, elMenuEntry[i]) )
      {
        strcpy(address, elPmacAddr[i]);
        ret = 0;
        break;
      }
    }
    else if( !strcmp(card, cw) )
    {
      if( !strcmp(name, cwMenuEntry[i]) )
      {
        strcpy(address, cwPmacAddr[i]);
        ret = 0;
        break;
      }
    }
  }
  return(ret);
}


void readDataSet( long *azFlag, long *elFlag, long *cwFlag, char *dataset )
{
  char (*ptrC)[FIELD_SIZE];
  /* Removed during EPICS 7 Migration
  int  numElements;
  */
  int  i;

  *azFlag = 0;
  *elFlag = 0;
  *cwFlag = 0;

  if( !strcmp(dataset, "DATASET1") )
  {
    ptrC        = dataset1C;
  /* Removed during EPICS 7 Migration
    numElements = index1;
    */
  }
  else if( !strcmp(dataset, "DATASET2") )
  {
    ptrC        = dataset2C;
  /* Removed during EPICS 7 Migration
    numElements = index2;
    */
  }
  else if( !strcmp(dataset, "DATASET3") )
  {
    ptrC        = dataset3C;
  /* Removed during EPICS 7 Migration
    numElements = index3;
    */
  }
  else if( !strcmp(dataset, "DATASET4") )
  {
    ptrC        = dataset4C;
  /* Removed during EPICS 7 Migration
    numElements = index4;
    */
  }
  else
  {
     epicsPrintf("readDataSet(): bad dataset name %s\n", dataset);
     return;
  }

  for(i=0; i<MAX_NUM_LOGGED; i++)
  {
    if( !strncmp(ptrC[i], az, 2) )
      *azFlag = 1;
    else if( !strncmp(ptrC[i], el, 2) )
      *elFlag = 1;
    else if( !strncmp(ptrC[i], cw, 2) )
      *cwFlag = 1;
  }
}


/* Decodes a Decimal into a 4-bit binary and populates datasets
   accordingly
*/

void construct_dataset( int num, char *label, char *stringT, char *stringA, char *card )
{
  switch( num )
  {
    case 0:
      break;

    case 1:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      break;

    case 2:
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      break;

    case 3:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      break;

    case 4:
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      break;

    case 5:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      break;

    case 6:
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      break;

    case 7:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      break;

    case 8:
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 9:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 10:
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 11:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 12:
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 13:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 14:
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;

    case 15:
      strcpy(dataset1L[index1],   label);
      strcpy(dataset1C[index1],   card);
      strcpy(dataset1T[index1],   stringT);
      strcpy(dataset1A[index1++], stringA);
      strcpy(dataset2L[index2],   label);
      strcpy(dataset2C[index2],   card);
      strcpy(dataset2T[index2],   stringT);
      strcpy(dataset2A[index2++], stringA);
      strcpy(dataset3L[index3],   label);
      strcpy(dataset3C[index3],   card);
      strcpy(dataset3T[index3],   stringT);
      strcpy(dataset3A[index3++], stringA);
      strcpy(dataset4L[index4],   label);
      strcpy(dataset4C[index4],   card);
      strcpy(dataset4T[index4],   stringT);
      strcpy(dataset4A[index4++], stringA);
      break;
  }
}


void decodeAddress( char *addrIn, int *num, char *retType, char *retAddr )
{
  char *string;
  char tempStr[MAX_STRING_SIZE];

  strcpy(tempStr, addrIn);
  string  = (char *)strtok(tempStr, " ,:,$");
  *num    = atoi(string);
  strcpy( retType, (char *)strtok(NULL, " ,:,$") );
  strcpy( retAddr, (char *)strtok(NULL, " ,:,$") );
}



static const iocshArg mcCaInitLogSetupArg0 = {"top", iocshArgString };
static const iocshArg mcCaInitLogSetupArg1 = {"az", iocshArgString };
static const iocshArg mcCaInitLogSetupArg2 = {"el", iocshArgString };
static const iocshArg mcCaInitLogSetupArg3 = {"cw", iocshArgString };

static const iocshArg *mcCaInitLogSetupArgs[] = { &mcCaInitLogSetupArg0,
                                                  &mcCaInitLogSetupArg1,
                                                  &mcCaInitLogSetupArg2,
                                                  &mcCaInitLogSetupArg3 };

static const iocshFuncDef mcCaInitLogSetupFuncDef =
         {"caInitLogSetup", 4, mcCaInitLogSetupArgs};

static void caInitLogSetupCallFunc(const iocshArgBuf *args)
{
   caInitLogSetup(args[0].sval,args[1].sval,args[2].sval,args[3].sval);
}

static void mcRegisterCaInitLogCommands(void)
{
      iocshRegister(&mcCaInitLogSetupFuncDef, caInitLogSetupCallFunc);
}
epicsExportRegistrar(mcRegisterCaInitLogCommands);

epicsExportAddress(int, caLogDataDriverDebug);
