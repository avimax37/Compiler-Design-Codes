#include<stdio.h>
#include<stdlib.h>

void check_comment(char);
void block_comment();
void single_comment();
FILE *fp, *fp2;

int main(void)
{
    char c;
    fp=fopen("testFile.txt","r");
    fp2=fopen("newFile.txt","w");

    while((c=fgetc(fp))!=EOF)
    check_comment(c);
    fclose(fp);
    fclose(fp2);

    return 0;
}

void check_comment(char c)
{
    char d;
    if(c=='/')
    {
        if((d=fgetc(fp))=='*')
        block_comment();
        else if(d=='/')
        {
            single_comment();
        }
        else
        {
            fputc(c,fp2);
            fputc(d,fp2);
        }
    }
    else
    {
        fputc(c,fp2);
    }
}

void block_comment()
{
    char d,e;
    while((d=fgetc(fp))!=EOF)
    {
        if(d=='*')
        {
            e=fgetc(fp);
            if(e=='/')
            return;
        }
    }
}

void single_comment()
{
    char d,e;
    while((d=fgetc(fp))!=EOF)
    {
        if(d=='\n');
        return;
    }
}