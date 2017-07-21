#define MAX_MENU_ENTRIES  16
#define FIELD_SIZE         5
#define NUM_PMAC_CARDS     3
#define FIRST_LOG_SOURCE   2
#define LAST_LOG_SOURCE   25
#define LOGGED_PER_PMAC   (LAST_LOG_SOURCE - FIRST_LOG_SOURCE)
#define MAX_NUM_LOGGED    (NUM_PMAC_CARDS * LOGGED_PER_PMAC)
#define TYPE_SIZE          2
#define STATE_FIELD_SIZE  16
#define READ_CHANNELS      0
#define WRITE_CHANNELS     1
#define READ_HEADER        2
#define SWITCH_OFF         3
#define HEADER_SIZE       ((LOGGED_PER_PMAC+1)*(STATE_FIELD_SIZE+14) + 4)

/*
   HEADER_SIZE is: 
     3     characters for the number of sources
     24*30 character fields to hold source identifiers + blank at end
     1     character for new line at end of string '\n'
*/

/* Function Prototypes */

void  caInitLogSetup( char *, char *, char *, char * );
void  caLogDataTask( void * );
void  caReadLogSetup( long *, long *, long * );
void  caReadHeader( char *, char * );
void  caWriteLogSetup( char * );

int   getAddress( char *, char *, char * );
void  readDataSet( long *, long *, long *, char * );
void  construct_dataset( int, char *, char *, char *, char * );
void  decodeAddress( char *, int *, char *, char * );
