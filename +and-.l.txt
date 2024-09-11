%{
int positive_no = 0, negative_no = 0;
%}
%%
[-][0-9]+ {negative_no++;}
[0-9]+ {positive_no++;} 
%%
int yywrap()
{}
int main()
{
printf("enter number:\n");
yylex();
printf ("number of positive numbers = %d\n",positive_no);
printf("number of negative numbers = %d\n",negative_no);
return 0;
}