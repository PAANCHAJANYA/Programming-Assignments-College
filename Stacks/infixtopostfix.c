//infix expression to postfix expression conversion for expression pure of variables free from real numbers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct st
{
    int top;
    int capacity;
    int* array;
};
struct st* createStack(int capacity )
{
    struct st* stack = (struct st*)malloc(sizeof(struct st));
    if (!stack)
        return NULL;
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct st* stack)
{
    return stack->top==-1 ;
}
char peek(struct st* stack)
{
    return stack->array[stack->top];
}
char pop(struct st* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct st* stack, char op)
{
    stack->array[++stack->top] = op;
}
int isOperand(char ch)
{
    return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
int infixToPostfix(char* exp)
{
    int i, k;
    struct st* stack=createStack(strlen(exp));
    if(!stack)
        return -1 ;
    for(i=0,k=-1;exp[i];++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack)&&Prec(exp[i])<=Prec(peek(stack)))
                exp[++k]=pop(stack);
            push(stack,exp[i]);
        }
    }
    while (!isEmpty(stack))
        exp[++k]=pop(stack );
    exp[++k]='\0';
    printf("%s", exp);
}
int main()
{
	char str1[25];
	printf("\nEnter the expression in variables without containing the numbers such as 'a^b+c' but 'not 2+c-3' since this program illustrates the conversion of infix expressions to postfix expressions only:\n");
	scanf("%s", str1);
	infixToPostfix(str1);
	return 0;
}
