#include<iostream>
using namespace std;
void merge(int *arr, int l, int m, int r)
{
   int i,j,k,nl,nr;
   nl=m-l+1;
   nr=r-m;
   int larr[nl],rarr[nr];
   for(i=0;i<nl;i++)
      larr[i]=arr[l+i];
   for(j=0;j<nr;j++)
      rarr[j]=arr[m+1+j];
   i=0;j=0;k=l;
   while(i<nl&&j<nr)
   {
      if(larr[i]<=rarr[j])
      {
         arr[k]=larr[i];
         i++;
      }
      else
      {
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl)
    {
      arr[k]=larr[i];
      i++;
      k++;
   }
   while(j<nr)
   {
      arr[k] = rarr[j];
      j++;
      k++;
   }
}
void mergeSort(int *arr, int l, int r)
{
   int m;
   if(l<r)
    {
      int m=l+(r-l)/2;
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
   }
}
int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++)
      cin >> arr[i];
   cout << "Array before Sorting: ";
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
   mergeSort(arr, 0, n-1);
   cout << "Array after Sorting: ";
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
