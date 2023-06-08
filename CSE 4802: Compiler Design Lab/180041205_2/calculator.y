%{
#include <stdio.h>
#include <stdlib.h>
int regs[26];
int base;
/*
    Syed Rifat Raiyan
	180041205
    IUT CSE-18
*/
%}
%start list

%token LETTER NUMBER

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%right '^'
%left UMINUS  /*supplies precedence for unary minus */

%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr { printf("%d\n",$1); }
        | LETTER '=' expr { regs[$1] = $3;}
         ;

expr:    '(' expr ')' { $$ = $2; }
		 | expr '^' expr   { int prod=1,i,exp=abs($3); for(i=1; i<=exp; i++) prod*=$1; if($3<0){$$ = 1/prod;}else{$$ = prod;}} /* Handling both positive and negative powers. */
         | expr '*' expr   { $$ = $1 * $3;  }
         | expr '/' expr   { $$ = $1 / $3;  }
         | expr '%' expr { $$ = $1 % $3; }
         | expr '+' expr  { $$ = $1 + $3;  }
         | expr '-' expr   { $$ = $1 - $3;  }
         | expr '&' expr  { $$ = $1 & $3;  }
         | expr '|' expr   {  $$ = $1 | $3;  }
         | '-' expr %prec UMINUS { $$ = -$2; }
         | LETTER { $$ = regs[$1]; }
         | NUMBER  { $$ = $1; };

%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}