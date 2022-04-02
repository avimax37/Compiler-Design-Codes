%{
    #include<stdio.h>
    int lines=0, words=0, c_letters=0, num=0, total=0, spl_chr=0;
%}

%%
\n {lines++; words++;}
[\t' '] words++;
[a-z A-Z] c_letters++;
[0-9] num++;
. spl_chr++;
%%

int main()
{
    yyin=fopen("sampleFile.txt","r");
    yylex();
    total=c_letters+num+spl_chr;

    printf("\nFile contains the following:\n");
    printf("\n\t%d lines", lines);
    printf("\n\t%d words", words);
    printf("\n\t%d characters", c_letters);
    printf("\n\t%d digits", num);
    printf("\n\t%d special characters", spl_chr);
    printf("\n\tTotal %d characters", total);
}

int yywrap()
{
    return 1;
}