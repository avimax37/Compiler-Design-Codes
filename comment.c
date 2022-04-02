#include<stdio.h>
#include<string.h>

int isComment(char line[])
{
    if(line[0]=='/' && line[1]=='/' && line[2]!='/')
    return 1;
    if(line[strlen(line)-2]=='*' && line[strlen(line)-1]=='/' && line[0]=='/' && line[1]=='*')
    return 2;
}

int main()
{
    char line[100];
    printf("\nEnter a comment:\n");
    gets(line);
    if(isComment(line)==1)
    printf("\nSingle Line Valid COmment.\n");
    else if(isComment(line)==2)
    printf("\nMulti Line Valid Comment.\n");
    else
    printf("\nInvalid Comment.\n");
}