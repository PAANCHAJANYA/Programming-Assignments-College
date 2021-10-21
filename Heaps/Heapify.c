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
void HeapifyMin(int A[], int i, int size)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest=i;
	int k;
	if(left<size&&A[left]<A[i])
		smallest=left;
	if(right<size&&A[right]<A[smallest])
		smallest=right;
	if(smallest!=i)
    {
		k=A[i];
		A[i]=A[smallest];
		A[smallest]=k;
		HeapifyMin(A,smallest,size);
	}
}
void MinHeap(int A[], int n)
{
	int i=(n-2)/2;
	while(i>=0)
		HeapifyMin(A,i--,n);
}
int main()
{
    int *arr,i;
    printf("\nEnter the number of elements you want to heapify:");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements you want to heapify:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    buildMaxHeap(arr);
    printf("\nThe max heap generated after heapifying the given data is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    MinHeap(arr,n);
    printf("\nThe min heap generated after heapifying the given data is:");
	for (i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
/*OUTPUT:
Enter the number of elements you want to heapify:10

Enter the elements you want to heapify:17 19 3 10 8 40 12 50 48 6

The max heap generated after heapifying the given data is:50 48 40 19 8 3 12 10 17 6
The min heap generated after heapifying the given data is:3 6 12 10 8 40 50 19 17 48*/
