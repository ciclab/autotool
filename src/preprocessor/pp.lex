%{
#include "perr.h"
%}

%x IN_COMMENT
%option yylineno
%%
"//"[^\n]* {}

<INITIAL>{
"/*" BEGIN(IN_COMMENT);
}

<IN_COMMENT>{
"*/" BEGIN(INITIAL);
[^*\n]+ // eat comment in chunks
"*" // eat the lone star
\n {ECHO;PE}
}

. {ECHO;}

%%
int yywrap()
{
  return 1;
}
int main(int argc,char *argv[])
{
  yylex();
  return 0;
}
