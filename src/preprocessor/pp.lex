%{
#include "perr.h"
%}

%x IN_COMMENT
%option nounput
%option yylineno
%%

"#"[^\n]* {}

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
