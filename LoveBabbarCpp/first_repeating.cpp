// #include<iostream>
// using namespace std;

// int  firstRepeatingElement(int arr[], int n)
// {
//     for(int i=0; i <= n ; i++)
//     {
//         for(int j=i+1; j <= n ; j++)
//         if(arr[i]==arr[j])
//         {
//             return i; 
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[]={ 1,2,3,4,2,3};
//     int n=6;
    
//     if(firstRepeatingElement(arr, n)==-1)
//     {
//         cout<<"Element not found";
//     }
//     else{
//         cout<<"Element found at:"<< firstRepeatingElement(arr, n)<<" ";
//     }
//     return 0;
    
// }
#include <iostream>
using namespace std;

int firstRepeatingElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the current element is repeated
            if (arr[i] == arr[j]) {
                return i; // Return the index of the first repeating element
            }
        }
    }
    return -1; // Return -1 if no repeating element is found
}

int main() {
    int arr[] = {1, 24, 3,34,24, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Determine the size of the array

    int result = firstRepeatingElement(arr, n);
    
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "First repeating element found at index: " << result << " (Element: " << arr[result] << ")" << endl;
    }
    
    return 0;
}
