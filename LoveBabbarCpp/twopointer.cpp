#include<iostream>
using namespace std;

bool TwoSum(int arr[], int n , int target)
{
    for(int i=0; i<n ; i++)
    {
        for(int j=i+1; j<n ; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return true;
            }

        }
    }
    return false;
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=6;
    int target=5;

    cout<<"Target found : "<< TwoSum(arr,n,target)<<endl;

}