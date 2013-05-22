#include <cstdio>
#include <cstdlib>

#ifndef PE_D
#define PE_D 1
#define PE {\
fprintf(stderr,"INTERNAL_ERROR\n\
FILE:%s\n\
LINE:%d\n\
FUNC:%s\n",__FILE__,__LINE__,__FUNCTION__);\
exit(1);}
#endif