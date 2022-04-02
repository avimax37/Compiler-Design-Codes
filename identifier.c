#include<stdio.h>
#include<string.h>

int isValid(char str[], int n)
{
    int i;
    if(!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str[0]=='_'))
    return 0;
    for(i=1;i<n;i++)
    {
        if(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]=='_'))
        return 0;
    }
    return 1;
}

int main()
{
    char str[30], ch;
    int length, n;
    printf("\nEnter an identifier:\n");
    gets(str);
    length=strlen(str);
    n=length;
    if(isValid(str,length)==1)
    printf("\nValid Identifier.\n");
    else
    printf("\nInvalid Identifier.\n");
}