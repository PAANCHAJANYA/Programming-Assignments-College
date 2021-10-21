//Matching Parenthesis

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct st
{
	int items[25];
	int top;
};
int main()
{
	clock_t start,stop;
	double d;
	char str1[50];
	int i;
	struct st *s;
	struct st *t;
	s=(struct st*)malloc(sizeof(struct st));
	t=(struct st*)malloc(sizeof(struct st));
	s->top=-1;
	t->top=-1;
	printf("Enter the expression:");
	scanf("%s", str1);
	start=clock();
	for(i=0;i<strlen(str1);i++)
	{
		if(str1[i]=='(')
		{
			s->top++;
			s->items[s->top]=i;
		}	
		if(str1[i]==')')
		{
			t->top++;
			t->items[t->top]=i;
			printf("(%d,%d) ", (s->top>=0)?s->items[s->top--]:-1, t->items[t->top--]);
		}
	}
	if((s->top)>=0)
	{
	for(i=0;i<(s->top);i++)
		printf("(%d,%d) ", s->items[s->top--], -1);
	}
	printf("\n'-1' at one of the coordinates indicate that the pair is mismatched\n");
	stop=clock();
	d=(double)stop-start;
	printf("TIME LAPSE:%.4f ms\n", d);
	return 0;
}

