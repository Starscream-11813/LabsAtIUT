%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
    Syed Rifat Raiyan
	180041205
    IUT CSE-18
*/
char st[100][50];
int indx=0;
void pushNum();
void pushId();
char* top();
void process(char* a);
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

start:    expr
         {
           printf("\n=%s\n",top());
         };

expr:    expr expr '^' { process(" ^ ");}
		 | expr expr '*' { process(" * ");}
         | expr expr '/' { process(" / ");}
         | expr expr '%' { process(" % ");}
         | expr expr '+' { process(" + ");}
         | expr expr '-' { process(" - ");}
         | expr expr '&' { process(" & ");}
		 | expr expr '|' { process(" | ");}
         | NUMBER  { pushNum($1);}
		 | ID  { pushId($1);};



%%
main()
{
	return(yyparse());
}

void pushNum(int a)
{  
	char tmp[20]; 	
	sprintf(tmp, "%d", a);
	strcpy(st[indx++],tmp);
}

void pushId(char* a)
{  
	char tmp[20]; 	
	sprintf(tmp, "%s", a);
	strcpy(st[indx++],tmp);
}

char* pop()
{
    return st[--indx];
}

char* top()
{
    return st[indx-1];
}

void process(char* a)
{
    char buffer[50];
    char* c1=pop();
    char* c2=pop();
    //bzero(buffer,20);
    memset(buffer, 0, 50);
    strcat(buffer,"(");
    strcat(buffer,c2);
    strcat(buffer,a);
    strcat(buffer,c1);
    strcat(buffer,")");
    strcpy(st[indx++],buffer);
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