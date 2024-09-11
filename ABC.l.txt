%{
%}
%%
[a-z] { printf("%c",yytext[0]-32);}
[A-Z] { printf("%c", yytext[0]);}
%%
int yywrap(){}
int main() 
{
 printf("enter the string\n");
 yylex();
 return 0;
}