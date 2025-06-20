#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;//dynamic array 
    int size;
    int top;

    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->top=-1;
    }

    void push(int data){
        if(top == size-1){
            cout<< " Stack Overflow"<<endl;
            return;
        }else{
            top++;
            arr[top]=data;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack Underflow"<<endl;
            return;
        }else{
            top--;
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    int getTop(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }else{
            return arr[top];
        }
    }


    void print(){
        for(int i=0; i< getSize(); i++){
            cout<< arr[i]<<" " << endl;
        }
    }

};

int main(){

    //create a stack
    Stack st(8);

    //push
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(8);
    st.print();

    st.pop();
    st.pop();

    cout<<"top Element will be :"<<st.getTop()<<endl;

    st.pop();
    st.pop();
    st.getSize();
    st.pop();

}