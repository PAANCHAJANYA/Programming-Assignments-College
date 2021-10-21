/*Write a program in c to implement the following function on the given polynomial. Coefficient coef(poly,expon)::=if(expon belongs to poly) then return its coeff else return 0.
NOTE : Use struct as well as array data structures to store given polynomial*/

#include<stdio.h>
#include<stdlib.h>
int coeff(int a);
int n;
struct krishna
{
	int coefficient;
	int exponent;
}k[10];
int main()
{
	int x,z,i;
	printf("Enter the degree of the polynomial:");
	scanf("%d", &n);
	for(i=n;i>=0;i--)
	{
		printf("\nEnter the coefficient of x with power %d:", i);
		scanf("%d", &k[i].coefficient);
		k[i].exponent=i;
	}
	printf("The polynomial is: ");
	for(i=n;i>=1;i--)
		printf("%dx^%d%c", k[i].coefficient, k[i].exponent, (k[i-1].coefficient>=0)?'+':'\0');
	printf("%d", k[0].coefficient);
	printf("\nEnter the exponent of the variable whose coefficient is to be found:");
	scanf("%d", &x);
	z=coeff(x);
	printf("The coefficient of the term in the polynomial whose power is %d is %d\n", x, z);
return 0;
}
int coeff(int a)
{
	if(k[a].coefficient!=0)
		return k[a].coefficient;
	else if(a>n)
		return 0;
	else
	{
		printf("\nNot a valid exponent\n");
		exit(1);
	}
}
