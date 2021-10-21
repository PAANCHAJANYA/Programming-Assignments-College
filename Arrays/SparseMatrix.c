/*Read two sparse matrices and find their sum, difference and transpose sparse matrices. Make suitable assumptions.*/

#include<stdio.h>
int main()
{
	struct krishna
	{
		int row;
		int col;
		int value;
	}k[50];
	int rows1, cols1, i, j, rows2, cols2;
	int x=0;
	int arr1[5][5];
	int arr2[5][5];
	printf("Enter the number of rows and columns:");
	scanf("%d%d", &rows1, &cols1);
	printf("\nEnter the elements of an array:");
	for(i=0;i<rows1;i++)
	{
	for(j=0;j<cols1;j++)
	{
		scanf("%d", &arr1[i][j]);
	}
	}
	printf("\nThe sparse matrix:");
	printf("\nROW\tCOLUMN\tELEMENT");
	for(i=0;i<rows1;i++)
	{
	for(j=0;j<cols1;j++)
	{
		if(arr1[i][j]!=0)
		{
			k[x].row=i;
			k[x].col=j;
			k[x].value=arr1[i][j];
			printf("\n%d\t%d\t%d\n", k[x].row, k[x].col, k[x].value);
			x++;
		}
	}
	}
	printf("\nThe number of non zero elements are %d", x);
	printf("\nEnter the number of rows and columns:");
	scanf("%d%d", &rows2, &cols2);
	printf("\nEnter the elements of an array for further operations:");
	for(i=0;i<rows2;i++)
	{
	for(j=0;j<cols2;j++)
	{
		scanf("%d", &arr2[i][j]);
	}
	}
	printf("\nTRANSPOSE OF THE SPARSE MATRIX:");
	x=0;
	for(j=0;j<cols1;j++)
	{
	for(i=0;i<rows1;i++)
	{
		if(arr1[i][j]!=0)
		{
			k[x].row=i;
			k[x].col=j;
			k[x].value=arr1[i][j];
			printf("\n%d\t%d\t%d\n", k[x].col, k[x].row, k[x].value);
			x++;
		}
	}
	}
	printf("\nThe number of non zero elements are %d", x);
	if((rows1==rows2)&&(cols1==cols2))
	{
		x=0;
		printf("\nADDITION OF THE SPARSE MATRICES:");
		for(i=0;i<rows1;i++)
		{
		for(j=0;j<cols1;j++)
		{
			if((arr1[i][j]+arr2[i][j])!=0)
			{
				k[x].row=i;
				k[x].col=j;
				k[x].value=arr1[i][j]+arr2[i][j];
				printf("\n%d\t%d\t%d\n", k[x].row, k[x].col, k[x].value);
				x++;
			}
		}
		}
		printf("\nThe number of non zero elements are %d", x);
		x=0;
		printf("\nSUBTRACTION OF THE SPARSE MATRICES:");
		for(i=0;i<rows1;i++)
		{
		for(j=0;j<cols1;j++)
		{
			if((arr1[i][j]-arr2[i][j])!=0)
			{
			k[x].row=i;
			k[x].col=j;
			k[x].value=arr1[i][j]-arr2[i][j];
			printf("\n%d\t%d\t%d\n", k[x].row, k[x].col, k[x].value);
			x++;
			}
		}
		}
		printf("\nThe number of non zero elements are %d", x);
	}
	else
		printf("\nNot Possible");
	return 0;
}
