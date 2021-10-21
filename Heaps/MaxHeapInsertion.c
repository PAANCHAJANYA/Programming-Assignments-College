#include<stdio.h>
#include<stdlib.h>
int n;
void swap(int array[],int firstItemIndex,int lastItemInde)
{
  int tmp=array[firstItemIndex];
  array[firstItemIndex]=array[lastItemInde];
  array[lastItemInde]=tmp;
}
void heapify(int heap[],int i,int max)
{
  int index, leftChild, righChild;
  while(i<max)
  {
    index=i;
    leftChild=2*i+1;
    righChild=leftChild+1;
    if(leftChild<max&&heap[leftChild]>heap[index])
      index=leftChild;
    if(righChild<max&&heap[righChild]>heap[index])
      index=righChild;
    if(index==i)
    return;
    swap(heap,i,index);
    i=index;
  }
}
void buildMaxHeap(int array[])
{
  int i;
  i=(n/2)-1;
  while (i>=0)
  {
    heapify(array,i,n);
    i-=1;
  }
}
void insertNode(int arr[],int Key)
{
    n++;
    arr[n-1]=Key;
    buildMaxHeap(arr);
}
int main()
{
    int *arr,i,key;
    printf("\nEnter the number of elements you want to heapify:");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*(n+4));
    printf("\nEnter the elements you want to heapify:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    buildMaxHeap(arr);
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    printf("\nEnter the element to be inserted:");
    scanf("%d",&key);
    insertNode(arr,key);
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    return 0;
}
/*OUTPUT:
Enter the number of elements you want to heapify:9

Enter the elements you want to heapify:1 3 36 42 7 91 100 42 9
100 42 91 42 7 1 36 3 9
Enter the element to be inserted:11
100 42 91 42 11 1 36 3 9 7*/
