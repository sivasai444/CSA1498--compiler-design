%{
%}
%%
[a-zA-Z]+ {printf("\n%s is word",yytext);}
">"|"<"|"<="|">="|"=="|"!=" {printf("\n%s is relational operator",yytext);}

%%
int yywrap(){}
int main()
{
printf("enter the input\n");
yylex();
}