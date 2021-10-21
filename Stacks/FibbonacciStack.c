//using stacks to grab fibonacci terms

#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int i=3;
int fibonacciStack(int a);
void push(int m);
int pop();
struct st
{
    int top;
    int items[MAX];
}*s;
int main()
{
    s=(struct st*)malloc(sizeof(struct st));
    int n,k;
    printf("Enter which Fibonacci term you want:");
    scanf("%d", &n);
    s->top=-1;
    push(0);
    push(1);
    k=fibonacciStack(n);
    printf("The %d Fibonacci term is %d", n ,k);
    printf("\nThe total number of function calls = %d", (n==1&&n==2&&n==3)?1:(n-2));
    printf("\nNumber of additions that took place = %d", (n==1&&n==2)?0:(n-2));
    return 0;
}
int fibonacciStack(int a)
{
    int x,y;
    if(a==1)
    {
       return (0);
    }
    else if(a==2)
    {
        return (1);
    }
    else
    {
        x=pop();
        y=pop();
        push(y);
        push(x);
        push(x+y);
        if(i==a)
        {
            return pop();
        }
        else
        {
            i++;
            fibonacciStack(a);
        }
    }
}
void push(int m)
{
    s->top++;
    s->items[s->top]=m;
}
int pop()
{
    int b;
    b=s->items[s->top];
    s->top--;
    return b;
}
