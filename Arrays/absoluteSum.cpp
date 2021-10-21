#include<iostream>
using namespace std;
class Sum
{
public:
    static int absoluteSum(int arr[], int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=(arr[i]>=0)?arr[i]:(-1*arr[i]);
        return sum;
    }
};
int main()
{
    int n, *arr, s;
    cout<<"Enter the number of elements:";
    cin>>n;
    arr=new int[n];
    cout<<"\nEnter the elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    s=Sum::absoluteSum(arr,n);
    cout<<"\nThe absolute sum is "<<s;
}

