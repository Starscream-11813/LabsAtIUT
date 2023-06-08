%{
// LIBRARIES AND VARIABLES
#include<stdio.h>
#include<string.h>
int wordCount=0;
int numCount=0;
int charCount=0;
int totalWords=0,totalNums=0,totalChars=0;
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
int main(argc,argv)
int argc;
char **argv;
{
	if(argc>1)
	{
		int i;
		for(i=1; i<argc; i++)
		{
			FILE *file;
			file=fopen(argv[i],"r");
			if(!file)
			{
				fprintf(stderr,"could not open %s\n",argv[1]);
				exit(1);
			}
			yyin=file;
			yylex();
			if(i==1)
			{
				printf("File_Name \t Words \t Numbers \t Characters\n");
			}
			printf("%s \t %d \t %d \t\t %d\n",argv[i], wordCount, numCount, charCount);
			totalWords+=wordCount;
			totalNums+=numCount;
			totalChars+=charCount;
			wordCount=0;
			numCount=0;
			charCount=0;
			fclose(file);
			if(i==argc-1)
			{
				printf("Total \t\t %d \t %d \t\t %d",totalWords, totalNums, totalChars);
			}
		}
	}
	return 0;
}

int yywrap()
{
	return 1;
}