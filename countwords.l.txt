%{
int c=0,i=0,l=0;
%}
%%
[\n] {l++;}
[ ] {i++;}
[a-zA-z0-9] {c++;}
%%
int yywrap(){}
int main()
{
  printf("enter input:\n");
  yylex();
  printf("no of lines are:%d\n",l);
  printf("no of words are:%d",i+1);
  printf("no of characters are:%d\n", c);
}