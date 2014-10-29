%{
#include "dy.h"
#include <stdio.h>
#include <assert.h>
#define YY_NO_INPUT
%}
BLANK [ \t]+
%option nounput
%%

"1" {return TOK_1;}
"0" {return TOK_0;}
. {assert(0);}

%%
int yywrap()
{
        return 1;
}
