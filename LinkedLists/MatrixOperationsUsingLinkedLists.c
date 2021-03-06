//Implement matrix using linked list without using 2D array. Also implement all the operations of arrays.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct node1
	{
		int data;
		struct node1* link;
	}*n1[20];
	struct node2
	{
		int data;
		struct node2* link;
	}*n2[20];
	int i, j, rows1, rows2, cols1, cols2, sum=0, k;
	printf("Enter the number of rows and columns of the first matrix:");
	scanf("%d%d", &rows1, &cols1);
	for(i=0;i<rows1*cols1;i++)
	{
		n1[i]=(struct node1*)malloc(sizeof(struct node1));
	}
	printf("\nEnter the number of rows and columns of the second matrix:");
	scanf("%d%d", &rows2, &cols2);
	for(i=0;i<rows2*cols2;i++)
	{
		n2[i]=(struct node2*)malloc(sizeof(struct node2));
	}
	printf("\nEnter the elements of the first matrix:");
	for(i=0;i<rows1*cols1;i++)
	{
		scanf("%d", &n1[i]->data);
	}
	for(i=0;i<rows1*cols1-1;i++)
	{
		n1[i]->link=n1[i+1];
	}
	n1[i]->link=NULL;
	printf("\nEnter the elements of the second matrix:");
	for(i=0;i<rows2*cols2;i++)
	{
		scanf("%d", &n2[i]->data);
	}
	for(i=0;i<rows2*cols2-1;i++)
	{
		n2[i]->link=n2[i+1];
	}
	n2[i]->link=NULL;
	printf("MATRIX1:\n");
	for(i=0;i<rows1;i++)
	{
	for(j=0;j<cols1;j++)
	{
		printf("%d\t", n1[i*rows1+j]->data);
	}
		printf("\n");
	}
	printf("MATRIX2:\n");
	for(i=0;i<rows2;i++)
	{
	for(j=0;j<cols2;j++)
	{
		printf("%d\t", n2[i*rows2+j]->data);
	}
		printf("\n");
	}
	if((rows1==rows2)&&(cols1==cols2))
	{
		printf("ADDITION:\n");
		for(i=0;i<rows2;i++)
		{
		for(j=0;j<cols2;j++)
		{
			printf("%d\t", n1[i*rows2+j]->data+n2[i*rows2+j]->data);
		}
			printf("\n");
		}
		printf("SUBTRACTION:\n");
		for(i=0;i<rows2;i++)
		{
		for(j=0;j<cols2;j++)
		{
			printf("%d\t", n1[i*rows2+j]->data-n2[i*rows2+j]->data);
		}
			printf("\n");
		}
	}
	else
		printf("\nADDITION AND SUBTRACTION OF THE INPUT MATRICES IS NOT POSSIBLE\n");
	if(rows2==cols1)
	{
		printf("MULTIPLICATION:\n");
		for(i=0;i<rows1;i++)
		{
		for(j=0;j<cols2;j++)
		{
		for(k=0;k<rows2;k++)
		{
			sum+=(n1[i*rows1+k]->data)*(n2[k*rows2+j]->data);
		}
			printf("%d\t", sum);
			sum=0;
		}
			printf("\n");
		}
	}
	else
		printf("\nMULTIPLICATION OF THE INPUT MATRICES IS NOT POSSIBLE\n");
	printf("TRANSPOSE OF MATRIX 1:\n");
	for(j=0;j<cols1;j++)
	{
	for(i=0;i<rows1;i++)
	{
		printf("%d\t", n1[i*rows1+j]->data);
	}
		printf("\n");
	}
		printf("TRANSPOSE OF MATRIX 2:\n");
	for(j=0;j<cols2;j++)
	{
	for(i=0;i<rows2;i++)
	{
		printf("%d\t", n2[i*rows2+j]->data);
	}
		printf("\n");
	}
	sum=0;
	printf("TRACE OF MATRIX 1:");
	for(i=0;i<rows1;i++)
	{
	for(j=0;j<cols1;j++)
	{
		if(i==j)
		sum+=n1[i*rows1+j]->data;
	}
	}
	printf("%d\n", sum);
	sum=0;
	printf("TRACE OF MATRIX 2:");
	for(i=0;i<rows2;i++)
	{
	for(j=0;j<cols2;j++)
	{
		if(i==j)
		sum+=n2[i*rows2+j]->data;
	}
	}
	printf("%d", sum);
	return 0;
}
