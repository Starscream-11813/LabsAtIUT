%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Syed Rifat Raiyan
	180041205
    IUT CSE-18
*/
int yylex();
%}

%union
{
	char* identifier;
	int number;
}

%token NUMBER
%token ID
%token other

%type<identifier> ID
%type<number> NUMBER
%type<identifier> start expr

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%right '^'
%%                   /* beginning of rules section */

list:                       /*empty */
         | list start '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

start:   expr
         {
           printf("\n");
         };

expr:    '(' expr ')'
		 | expr '^' expr   { printf("^ ");}
         | expr '*' expr   { printf("* ");}
         | expr '/' expr   { printf("/ ");}
         | expr '%' expr { printf("% ");}
         | expr '+' expr  { printf("+ ");}
         | expr '-' expr   { printf("- ");}
		 | expr '&' expr   { printf("& ");}
		 | expr '|' expr   { printf("| ");}
         | NUMBER  { printf("%d ",$1);}
		 | ID  { printf("%s ",$1);};


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