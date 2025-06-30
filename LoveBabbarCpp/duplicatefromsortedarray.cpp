#include<iostream>
using namespace std;

void DuplicateFromSortedArray(int arr[], int n)
{ 
  int i=0;
  int j=i+1;
  while(j<n)
    {
      if(arr[i]==arr[j])
      {
        cout<< arr[i] << endl;
        i++;
        j++;
      }
      else{
        i++;
        j++;
      }
    }
}

int main()
{
  int arr[10]={0,0,1,1,1,2,2,3,3,4};
  int n=10;
  DuplicateFromSortedArray( arr ,n);
  
}