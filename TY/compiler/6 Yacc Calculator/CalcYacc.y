%{
#include<stdio.h>
int yylex();
void yyerror();
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: T{

	printf("\nResult=%d\n", $$);

	return 0;

	};
T: T '+' T {$$ = $1 + $3;}
|T '-' T {$$ = $1 - $3;}
|T '*' T {$$ = $1 * $3;}
|T '/' T {$$ = $1 / $3;}
|T '%' T {$$ = $1 % $3;}
|'('T')' {$$ = $2;}
| NUMBER {$$=$1;}
|  error '\n' {yyerror("Error: reenter last line:");
	yyerrok; };
;
%%

#include "lex.yy.c"
int main(void){
	yyparse();
}
void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n\n");
   //flag=1;
}
