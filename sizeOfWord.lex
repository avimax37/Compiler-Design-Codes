%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
([a-z] | [A-Z])* {printf("%ld", strlen(yytext));}
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
}