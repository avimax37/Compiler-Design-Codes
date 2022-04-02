%{
    int vowel=0;
    int consonant=0;
%}

%%
[aeiou AEIOU] {vowel++;}
[a-z A-Z] {consonant++;}
%%

int yywrap() {}

int main()
{
    printf("\nEnter a string:\n");
    yylex();
    printf("Number of vowels is: %d\n", vowel);
    printf("Number of consonant is: %d\n", consonant);
    yywrap();
    return 0;
}