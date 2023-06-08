%{
// LIBRARIES AND VARIABLES
#include<stdio.h>
#include<string.h>
int wordCount=0;
int numCount=0;
int charCount=0;
%}

%%
[\t ]+       {charCount+=strlen(yytext);}
[a-zA-Z][-a-zA-Z0-9]*+     {wordCount++; charCount+=strlen(yytext);}
[+-]?([0-9]*[.])?[0-9]+ {numCount++; charCount+=strlen(yytext);}
. {charCount+=strlen(yytext);}


%%
/*
    Syed Rifat Raiyan
	180041205
    IUT CSE-18
*/
// SUBROUTINES
int main()
{
	printf("Enter a string: ");
	yylex();
	printf("Words \t Numbers \t Characters\n");
	printf("%d \t %d \t\t %d",wordCount, numCount, charCount);
	return 0;
}

int yywrap()
{
	return 1;
}