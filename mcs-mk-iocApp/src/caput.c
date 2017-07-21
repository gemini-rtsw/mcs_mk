#include <caerr.h>
#include <cadef.h>
#include <db_access.h>
#include <string.h>

int caput( char *name )
{
  int   is;
  int   is1;
  chid  id;
  char  buf[32];
  double val;

  strcpy( buf, name );

  val = 3.0;
  is  = ca_task_initialize();
  is  = ca_search( buf, &id);
  is1 = ca_pend_io(5.0);
  is1 = ca_flush_io();
  if( is != ECA_NORMAL )
    SEVCHK(is,"ca_search failed!\n");
  is = ca_put( DBR_DOUBLE, id, &val );
  is = ca_pend_io(5.0);
  is = ca_flush_io();
  return(0);
}
