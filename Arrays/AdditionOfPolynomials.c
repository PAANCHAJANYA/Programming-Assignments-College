//ADDITION OF POLYNOMIALS.

#include<stdio.h>
#include<stdlib.h>
struct polynomial1
{
	int coefficient;
	int exponent;
}k[10];
struct polynomial2
{
	int coefficient;
	int exponent;
}l[10];
int main()
{
	int x,z,i,n1,n2;
	printf("Enter the degree of the first polynomial:");
	scanf("%d", &n1);
	for(i=n1;i>=0;i--)
	{
	printf("\nEnter the coefficient of x with power %d:", i);
	scanf("%d", &k[i].coefficient);
	k[i].exponent=i;
	}
	printf("Enter the degree of the second polynomial:");
	scanf("%d", &n2);
	for(i=n2;i>=0;i--)
	{
	printf("\nEnter the coefficient of x with power %d:", i);
	scanf("%d", &l[i].coefficient);
	l[i].exponent=i;
	}
	printf("The first polynomial is: ");
	for(i=n1;i>=1;i--)
		printf("%dx^%d%c", k[i].coefficient, k[i].exponent, (k[i-1].coefficient>=0)?'+':'\0');
	printf("%d", k[0].coefficient);
	printf("\nThe second polynomial is: ");
	for(i=n2;i>=1;i--)
		printf("%dx^%d%c", l[i].coefficient, l[i].exponent, (l[i-1].coefficient>=0)?'+':'\0');
	printf("%d", l[0].coefficient);
	printf("\nAddition of the two polynomials is: ");
	for(i=((n1>n2)?n1:n2);i>=1;i--)
		printf("%dx^%d%c",k[i].coefficient+l[i].coefficient,(n1>n2)?k[i].exponent:l[i].exponent,(k[i-1].coefficient+l[i-1].coefficient>=0)?'+':'\0');
	printf("%d", k[0].coefficient+l[0].coefficient);
	printf("\n");
	return 0;
}
