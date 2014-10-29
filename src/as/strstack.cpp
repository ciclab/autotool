#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PE {fprintf(stderr,"INTERNAL_ERROR\tFILE:%s\tLINE:%d\tFUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);}
#define DBG_STRSTACK
#define STACK_SIZE (257)
#include "strstack.h"
#include <string.h>
int isnumber(const char *c)
{
  for(;*c;++c)
    if(*c<'0' || *c>'9')
      return 0;
  return 1;
}
// int s2i(char *buf,int width)
// {
// 	int i,r;
// 	for(i=r=0;i<width;++i)
// 		r=(r<<1)|buf[i];
// 	return r;
// }
char * s2hex(char *buf,int len)
{
  int val,i;
  for(val=i=0;i<len;++i)
    val=(val<<1)|(buf[i]=='1'?1:0);
  static char tmp[1000];/*TODO*/
  sprintf(tmp,"%X",val);
  return tmp;
}
const char * get_entry(const char * a[],const char * b,int num)
{
  int i,j;
  for(i=0;i<num;++i)
    {
      for(j=0;a[i<<1][j];++j)
	if(a[i<<1][j]!=b[j])
	  break;
      if(a[i<<1][j]=='\0')
	return a[(i<<1)+1];
    }
  return NULL;
}
// void con(char *a,char *b,int num)
// {
// 	int i,j;
// 	for(i=0;a[i];++i)
// 		;
// 	for(j=0;j<num;++j,++i)
// 		a[i]=b[j];
// 	a[i]=0;
// }
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
  {
    int i;
    for(i=0;i<num;++i)
      len+=strlen(str[i]);
  }
	
  (*ss).sta[(*ss).used]=(char *)calloc(len+1,sizeof(char));
#ifdef DBG_STRSTACK
  if((*ss).sta[(*ss).used]==NULL)
    {
      PE
	return 0;
    }
#endif
  {
    int i;
    for(i=0;i<num;++i)
      strcat((*ss).sta[(*ss).used],str[i]);
  }
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
