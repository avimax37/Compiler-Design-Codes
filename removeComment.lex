%{
    #include<stdio.h>
%}

%%
"//" ([a-z] | [A-Z] | [0-9] | " ")* {}
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
}