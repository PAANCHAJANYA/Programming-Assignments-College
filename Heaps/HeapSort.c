#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,n,i,root,a,k;
    printf("Enter number of elements:");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements:");
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        k=i;
        do
        {
            root=(k-1)/2;
            if(arr[root]<arr[k])
            {
                a=arr[root];
                arr[root]=arr[k];
                arr[k]=a;
            }
            k=root;
        }while(k!=0);
    }
    for(i=n-1;i>=0;i--)
    {
        a=arr[0];
        arr[0]=arr[i];
        arr[i]=a;
        root=0;
        do
        {
            k=2*root+1;
            if((arr[k]<arr[k+1])&&k<i-1)
                k++;
            if(arr[root]<arr[k]&&k<i)
            {
                a=arr[root];
                arr[root]=arr[k];
                arr[k]=a;
            }
            root=k;
        }while(k<i);
    }
    printf("\nThe sorted array is:");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}
/*OUTPUT:
Enter number of elements:5

Enter the elements:1 8 7 6 5

The sorted array is:1   5       6       7       8*/
