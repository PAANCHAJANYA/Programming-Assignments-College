//Implement queues using linked lists

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
int main()
{
struct node *n[10],*p;
int z,i,button,k=0,l=0;
printf("Enter the maximum number of elements you want to enter into the queue using linked lists:");
scanf("%d", &z);
for(i=0;i<z;i++)
{
n[i]=(struct node*)malloc(sizeof(struct node));
}
i=0;
for(i=0;i>=0;i++)
{
printf("\nPress 1 to insert data\nPress 2 to remove data\nPress 3 to print the queue and exit:");
scanf("%d", &button);
switch(button)
{
case 1:
	if(k==z)
	{
	printf("\nQueue is full!");
	break;
	}
	printf("\nEnter the data you want to insert:");
	scanf("%d", &n[k]->data);
	(k!=(z-1))?(n[k]->next=n[k+1]):(n[k]->next=NULL);
	k++;
	break;
case 2:
	if(k==0)
	{
	printf("\nQueue is empty!");
	break;
	}
	n[l]->next=NULL;
	free(n[l]);
	l++;
	k--;
	break;
case 3:
	p=n[l];
	while(p->next!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("%d", p->data);
	exit(0);
	break;
default:
	printf("\nWrong selection!");
}
}
return 0;
}
