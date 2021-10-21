/* Print the 2D array memory allocations along with the corresponding elements and hence identify whether array is implemented as row major or column major.
 Assume suitable size for the array*/

#include<stdio.h>
#include<time.h>
int main()
{
	int arr1[10][10];
	clock_t start,stop;
	double d,e;
	int rows,cols,i,j,button;
	printf("\nPress 1 if you want to select Row Major or 2 for Column Major:");
	scanf("%d", &button);
	if(button==1)
	{
		printf("\nEnter the number of rows and columns:");
		scanf("%d%d", &rows, &cols);
		printf("\nEnter the elements of the first array:");
		for(i=0;i<rows;i++)
		{
		for(j=0;j<cols;j++)
		{
			scanf("%d", &arr1[i][j]);
		}
		}
		start=clock();
		printf("\nRow Major:");
		printf("\nMemory Address\tElement\n");
		for(i=0;i<rows;i++)
		{
		for(j=0;j<cols;j++)
		{
			printf("%p\t%d\n", &arr1[i][j], arr1[i][j]);
		}
		}
		stop=clock();
		d=(double)stop-start;
		printf("TIME LAPSE:%.4f ms\n", d);
	}
	else if(button==2)
	{
		printf("\nEnter the number of rows and columns:");
		scanf("%d%d", &rows, &cols);
		printf("\nEnter the elements of the first array:");
		for(i=0;i<rows;i++)
		{
		for(j=0;j<cols;j++)
		{
			scanf("%d", &arr1[j][i]);
		}
		}
		start=clock();
		printf("\nColumn Major:");
		printf("\nMemory Address\tElement\n");
		for(i=0;i<rows;i++)
		{
		for(j=0;j<cols;j++)
		{
			printf("%p\t%d\n", &arr1[j][i], arr1[j][i]);
		}
		}
		stop=clock();
		e=(double)stop-start;
		printf("TIME LAPSE:%.4f ms\n", e);
	}
	else
		printf("\nNot a valid option");
	return 0;
}
