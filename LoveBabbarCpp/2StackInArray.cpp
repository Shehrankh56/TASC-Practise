#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int size){
        arr=new int[size];
        this->size=size;
        top1 = -1;
        top2 = size;

    }


    void push1(int data){

        if(top2 - top1 == 1){
            cout << "Overflow"<<endl;
        }
        ++top1;
        arr[top1]=data;
    }

    void push2(int data){

        if(top2 - top1 == 1){
            cout << "Overflow"<<endl;
        }
        --top2;
        arr[top2]=data;
    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack Underflow";
        }else{
            arr[top1]=0;
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout << "Stack Underflow";
        }else{
            arr[top2]=0;
            top2++;
        }
    }

    void print(){
        cout << endl;
        for(int i=0; i< size; i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
};

int main(){
    stack st(4);
    st.push1(10);
    st.push2(20);
    st.push1(30);
    st.push2(40);

    st.print();
}