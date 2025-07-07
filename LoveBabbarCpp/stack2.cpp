#include<iostream>
using namespace std;

class Stack
{
    public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        arr=new int[size];
        this->size=size;
        this->top=-1;
    }
    void push(int data)
    {
        if(top==size-1)
        {
            cout<<"overflow"<<endl;
            return ;

        }
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
            return;
        }
        else{
            top--;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    int getTop()
    {
        if(top==-1)
        {
            cout<<"stack is empty";
            return -1;
        }
        else{
             return arr[top];
        }
    }
    int getSize()
    {
        return top+1;
    }
    void print()
    {
        cout<<"Generated Stack is: "<<endl;
        for(int i=0; i < getSize() ; i++)
        cout<< arr[i]  <<" ";
        cout<< endl;
    }

};

int main()
{
    Stack st(8);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout<<"Top element is:"<< st.getTop()<<endl;
    cout<<"Size is :"<< st.getSize()<<endl;
    st.print();
    return 0;
 
}