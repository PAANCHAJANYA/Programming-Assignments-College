//Tower of hanoi problem with time of execution

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
void hanoiTower(int n, char fromRod, char toRod, char auxRod);
int main()
{
	clock_t start,stop;
	double d;
	int n ;
	printf("\nEnter no of disks:\n");
	scanf("%d",&n);
	if(n<=0)
    {
        printf("\nNot Possible!");
        exit(0);
    }
	start=clock();
	int q;
	q=pow(2,n)-1;
	printf("Total number of moves=%d\n",q);
	hanoiTower(n,'A','C','B');
	stop=clock();
	d=(double)stop-start;
	printf("\nTIME LAPSE:%.4f ms\n", d);
	return 0;
}
void hanoiTower(int n, char fromRod, char toRod, char auxRod)
{
    if(n==1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }
    hanoiTower(n-1,fromRod, auxRod, toRod);
    printf("\nMove disk %d from rod %c to rod %c", n, fromRod, toRod);
    hanoiTower(n-1, auxRod, toRod, fromRod);
}
