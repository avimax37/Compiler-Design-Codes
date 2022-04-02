%{
    #include<stdio.h>
    int sf=0, pf=0;
%}

%%
"scanf" {sf++;fprintf(yyout,"readf");}
"printf" {pf++;fprintf(yyout,"writef");}
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin=fopen("open.c","r");
    yyout=fopen("new.c","r");
    yylex();
    printf("\nNumber of scanfs= %d\n", sf);
    printf("\nNumber of printfs= %d\n", pf);

    return 0;
}