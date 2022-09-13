#include <caerr.h>
#include <cadef.h>
#include <db_access.h>
#include <string.h>

int caput( char *name )
{
  int   is;
  /* Removed during EPICS 7 migration
  int   is1;
  */
  chid  id;
  char  buf[32];
  double val;

  strcpy( buf, name );

  val = 3.0;
  is  = ca_task_initialize();
  is  = ca_search( buf, &id);
  /* Removed during EPICS 7 migration
  is1 = ca_pend_io(5.0);
  is1 = ca_flush_io();
  */
  ca_pend_io(5.0);
  ca_flush_io();
  if( is != ECA_NORMAL )
    SEVCHK(is,"ca_search failed!\n");
  is = ca_put( DBR_DOUBLE, id, &val );
  is = ca_pend_io(5.0);
  is = ca_flush_io();
  return(0);
}
