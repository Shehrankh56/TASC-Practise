#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0; i< n ; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
int main()
{
    int arr[]={1,4,5,6,3,2};
    int n=6;
    bubbleSort(arr,  n);
    cout<<"Printing Array:"<<endl;
    for(int i=0; i< n ; i++)
    {
        cout<<arr[i]<<" ";
    }

}