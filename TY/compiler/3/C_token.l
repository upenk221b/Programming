%{
#include<stdio.h>
#include<string.h>
%}
directives "#"[a-zA-Z<>.]+
keywords "if"|"else"|"break"|"continue"|"do"|"while"|"for"|"struct"|"typedef"|"union"|"return"
type "int"|"float"|"void"|"long"|"double"|"char"
type1 "int*"|"float*"|"void*"|"long*"|"double*"|"char*"
comment "//"[a-zA-Z ]+
operators "+"|"-"|"*"|"/"|"%"
numbers [0-9]+"."?[0-9]+
id [_a-zA-Z][a-zA-Z_0-9]+
%%
{directives} printf("C Directive: %s\n",yytext);
{keywords} printf("C Keyword: %s\n",yytext);
{comment} printf("Comment :%s\n",yytext);
{type} {printf("Data type : %s\n",yytext);}
{type1} printf("Pointer type : %s\n",yytext);
{operators} printf("Mathematical Operator : %s\n",yytext);
{numbers} printf(" Number : %s\n",yytext);
{id} {printf("Identifier : %s\n",yytext);}
. ;
%%
int main(int argc , char* argv[]){
	FILE *fp = fopen(argv[1],"r");
	if(fp){
		yyin = fp;
	}
	yylex();
return 0;
}
