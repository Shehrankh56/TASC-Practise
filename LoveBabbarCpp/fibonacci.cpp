#include<iostream>
using namespace std; 

int fib(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    int ans=fib(n-1)+fib(n-2);
    return ans;
    
}

int main()
{
    
    
    cout << "Fibonacci series is: ";
    for (int i = 0; i <= 5; i++) {  // print series up to 5th term
        cout << fib(i) << " ";
    }
    return 0;

}

