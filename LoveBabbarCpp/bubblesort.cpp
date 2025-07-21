#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0; i< n-1 ; i++)
    {
       for(int j=0; j < n-i-1; j++){
            if(arr[j] > arr[j+1] ){
                swap(arr[j+1], arr[j]);
            }
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