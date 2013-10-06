#ifndef __STRSTACK_H__
#define __STRSTACK_H__
struct strstack
{
	char ** sta;
	int used;
	int size;
};
void ini(struct strstack *ss);
void clear(struct strstack *ss);
int newstr(struct strstack *ss,int num,const char *str[]);
char* newstr1(struct strstack *ss,const char str[]);
const char * getstr(const struct strstack *ss,int k);
int getsize(const struct strstack *ss);
void i2bs(char *,int,int);
#endif
