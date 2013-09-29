#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_STRSTACK
#define STACK_SIZE (257)
#include "strstack.h"
void i2bs(char *buf,int v,int len)
{
  for(;len;v>>=1)
    buf[--len]=(v&1)?'1':'0';
}
void ini(struct strstack *ss)
{
  (*ss).size=STACK_SIZE;
  (*ss).used=0;
  (*ss).sta=(char **)calloc((*ss).size,sizeof(char*));
}
void clear(struct strstack *ss)
{
  for(;(*ss).used>0;--(*ss).used)
    free((*ss).sta[(*ss).used]);
}
char* newstr1(struct strstack *ss,const char str[])
{
  ++(*ss).used;
  if((*ss).used>=(*ss).size)
    {
      (*ss).size+=STACK_SIZE;
      (*ss).sta=(char **)realloc((*ss).sta,(*ss).size*sizeof(char*));
    }
  (*ss).sta[(*ss).used]=(char *)calloc(strlen(str)+1,sizeof(char));
#ifdef DBG_STRSTACK
  if((*ss).sta[(*ss).used]==NULL)
    {
      PE
	return 0;
    }
#endif
  strcpy((*ss).sta[(*ss).used],str);
  return (*ss).sta[(*ss).used];
}
int newstr(struct strstack *ss,int num,const char *str[]) 
{
  ++(*ss).used;
  if((*ss).used>=(*ss).size)
    {
      (*ss).size+=STACK_SIZE;
      (*ss).sta=(char **)realloc((*ss).sta,(*ss).size*sizeof(char*));
    }
  int len=0;
  for(int i=0;i<num;++i)
    len+=strlen(str[i]);
	
  (*ss).sta[(*ss).used]=(char *)calloc(len+1,sizeof(char));
#ifdef DBG_STRSTACK
  if((*ss).sta[(*ss).used]==NULL)
    {
      PE
	return 0;
    }
#endif
  for(int i=0;i<num;++i)
    strcat((*ss).sta[(*ss).used],str[i]);
  return (*ss).used;
}
const char * getstr(const struct strstack *ss,int k)
{
#ifdef DBG_STRSTACK
  if(k<=0 || k>(*ss).used)
    {
      printf("%d %d\n",k,(*ss).used);
      PE
	return NULL;
    }
#endif
  return (*ss).sta[k];
}
int getsize(const struct strstack *ss)
{
  return (*ss).used;
}
