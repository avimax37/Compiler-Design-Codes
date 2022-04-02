%{
    #include<stdio.h>
    #include<string.h>
    int i=0;
%}

%%
([a-z A-Z 0-9])* {i++;}
"\n" {printf("%d\n",i); i=0;}
%%

int yywrap(void) {}

int main()
{
    yylex();
    return 0;
}