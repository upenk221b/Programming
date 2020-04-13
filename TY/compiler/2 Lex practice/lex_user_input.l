%{
#include <stdio.h>
#include <string.h>
%}
%%
[^a-zA-Z0-9]+ printf("Special charactar : %s ", yytext);
[a-zA-Z0-9]+ printf("Alphaumeric String : %s ", yytext);

%%
int main(){
yylex();

}
