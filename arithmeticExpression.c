#include<stdio.h>
#include<string.h>

int stack2[30], temp, length=0, index=0, pos=0, top=-1;
char symbol, infix[20], postfix[20], stack[30];

void push(char);
void push2(int);
char pop();
int pop2();
int precedence(char);
void infix__to_postfix(char[]);
void eval_postfix(char[]);

void push(char symbol)
{
    top=top+1;
    stack[top]=symbol;
}

char pop()
{
    temp=stack[top];
    top=top-1;
    return temp;
}

int precedence(char symbol)
{
    int priority;
    switch(symbol)
    {
        case'#':
            priority=0;
            break;
        case'(':
        case')':
            priority=1;
            break;
        case'+':
        case'-':
            priority=2;
            break;
        case'*':
        case'/':
            priority=3;
            break;
        case'^':
            priority=4;
            break;
    }
    return priority;
}

void infix_to_postfix(char infix[])
{
    length=strlen(infix);
    push('#');
    while(index<length)
    {
        symbol=infix[index++];
        switch(symbol)
        {
            case'(':
                push(symbol);
                break;
            case')':
                temp=pop();
                while(temp!='(')
                {
                    postfix[pos++]=temp;
                    temp=pop();
                }
                break;
            case'-':
            case'+':
            case'*':
            case'/':
            case'^':
                while(precedence(stack[top])>=precedence(symbol))
                {
                    temp=pop();
                    postfix[pos++]=temp;
                }
                push(symbol);
                break;
            default:
                postfix[pos++]=symbol;
                break;
        }
    }
    while(top>0)
    {
        temp=pop();
        postfix[pos++]=temp;
        postfix[pos]='\o';
    }
}

void push2(int x)
{
    stack2[++top]=x;
}

int pop2()
{
    return stack2[top--];
}

void evaluate_postfix(char postfix[])
{
    char *temp;
    int n1, n2, n3, num;
    temp=postfix;
    while(*temp!='\o')
    {
        if(isDigit(*temp))
        {
            num=*temp-48;
            push2(num);
        }
        else
        {
            n1=pop2();
            n2=pop2();
            switch(*temp)
            {
                case'+':
                {
                    n3=n1+n2;
                    break;
                }
                case'-':
                {
                    n3=n2-n1;
                    break;
                }
                case'*':
                {
                    n3=n1*n2;
                    break;
                }
                case'/':
                {
                    n3=n2/n1;
                    break;
                }
            }
            push(n3);
        }
        temp++;
    }
    printf("\nThe result of the expression is= %d",pop2());
}

int main()
{
    printf("\nEnter an infix expression: \n");
    gets(infix);
    infix_to_postfix(infix);
    evaluate_postfix(postfix);

    return 0;
}