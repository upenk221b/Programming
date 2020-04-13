%{
#include<stdio.h>
#include<string.h>
int count=0,x=0,y=0;
%}
number [0-9]+  
verb	" am "|" is "|" are "|" was "|" were "|" has "|" had "|" will "|" shall "|" have " 
Article "A "|"An "|"The "
Article1 " a "|" an "|" the "
Pronoun	" he "|" she "|" it "
Pronoun1 "He "|"She "|"It "
%%
[ \t\n] count++;
{verb} {printf("Auxilary verb :%s\n",yytext ); x+=2;} //regular definations can be done as follows :

"Am "|"Is "|"Are "|"Was "|"Were "|"Has "|"Had "|"Will "|"Shall "|"Have " {printf("Auxilary verb :%s\n",yytext ); x++;}

{Article} {printf("Article : %s\n",yytext); x++;}//spaces are used on both sides so that bew'are' does not qualify as Auxilary verb
{Article1} {printf("Article : %s\n",yytext); x+=2;}

{Pronoun} {printf("Pronoun : %s\n",yytext); x+=2;}
{Pronoun1} {printf("Pronoun : %s\n",yytext); x++;}

"!"|"@"|"#"|"$"|"%"|"&"|"*"|"-"|"+" printf("Special character : %s\n",yytext );
. ; //do nothing on all other characters
%%
 //Articles like A ,An ,The only come at starting so leading space is ommited
int main(int argc , char *argv[] ){
	if(argc>1){
	FILE *fp = fopen(argv[1],"r");
	if(fp){
		yyin = fp;
	}		
}
yylex();
count=count+x;
printf("******NO OF WORDS = %d ********\n",count);
}
