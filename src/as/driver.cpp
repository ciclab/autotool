#include "l.h"
extern int dummy_parse();
#include "strstack.h"
strstack strsta;
char * yyret;
void dummy_getExpression(const char *str)
{
      printf("%s %s %d: %s\n",__FILE__,__FUNCTION__,__LINE__,str);
}
int main()
{
  char buf[4096];
  ini(&strsta);
  for(;;)
    {
      if(NULL==fgets(buf,sizeof(buf),stdin))
	break;
      printf("%s\n",buf);
      YY_BUFFER_STATE bs=dummy__scan_string(buf);
      dummy_parse();
      printf("%s",yyret);
      dummy__delete_buffer(bs);
      //printf("!%s\n",getstr(&strsta,getsize(&strsta)));
      clear(&strsta);
    }
}
