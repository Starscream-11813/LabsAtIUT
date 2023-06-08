%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
// int c;
// extern int yylval;
/*
    Syed Rifat Raiyan
	180041205
    IUT CSE-18
*/
%}

%%
" "	{ ; }

[0-9]+     { yylval.number = atoi(yytext); return(NUMBER); }
[a-zA-Z]*	{ yylval.identifier = strdup(yytext); return ID;}
[-+*/^&|()%]		{ return yytext[0]; }
.			{ return other; }
\n			{ return '\n'; }
%%