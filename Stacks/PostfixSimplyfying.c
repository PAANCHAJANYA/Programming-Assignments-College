//simplifying postfix expressions involving single digit operands

#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX 100
void EvalPostfix(char str1[]);
int pop();
void push(int a);
struct st
{
    int top;
    int items[MAX];
}*s;
int main()
{
    int i;
    char str1[100];
    s=(struct st*)malloc(sizeof(struct st));
    s->top=-1;
    printf("There are only four operators(*,/,+,-) in an expression and operand is single digit only.");
    printf("\nEnter postfix expression,\nPress right parenthesis ')' to end expression:");
    for(i=0;i<=99;i++)
    {
        scanf("%c", &str1[i]);
        if(str1[i]==')')
        {
            break;
        }
    }
    EvalPostfix(str1);
    return 0;
}
void push(int a)
{
    if (s->top>=MAX-1)
    {
        printf("\nStack Overflow");
        return;
    }
    else
    {
        s->top+=1;
        s->items[s->top]=a;
    }
}
int pop()
{
    int a;
    if(s->top<0)
    {
        printf("Stack Underflow");
    }
    else
    {
        a=s->items[s->top];
        s->top-=1;
        return a;
    }
}
void EvalPostfix(char str1[])
{
    int i,val,A,B;
    char ch;
    for (i=0;str1[i]!=')';i++)
    {
        ch=str1[i];
        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            A=pop();
            B=pop();
            switch (ch)
            {
            case '*':
                val=B*A;
                break;
            case '/':
                val=B/A;
                break;
            case '+':
                val=B+A;
                break;
            case '-':
                val=B-A;
                break;
            }
            push(val);
        }
    }
    printf("\nResult of expression evaluation :%d\n", pop());
}
