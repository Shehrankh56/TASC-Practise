#include<iostream>
using namespace std;

class Cqueue
{
  public:
  int *arr;
  int size;
  int front;
  int rear;

  Cqueue(int size)
  {
    arr=new int[size];
    this->size=size;
    front=-1;
    rear=-1;
  }
  
  void push(int val)
  { //circular nature 
    if(rear=size-1 && front!=0)
    {
        rear=0;
        arr[rear]=val;
    }
    else if((front==0 && rear=size-1) || rear==front-1)
    {  
        cout<<"overflow";
        return;

    }
    else if(front==-1 && rear==-1)
    {//empty case
        front++;
        rear++;
        arr[rear]=val;
    }
    else{//normal situation
        rear++;
        arr[rear]=val;
    }
  }

  void pop()
  {
    if(front==size-1 )
    {//circular nature
        arr[front]=-1;
        front=0;
    }
    else if(front==-1 && rear==-1)
    {
        cout<<"Underflow condition";
        return;
    }
    else if (front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
    }
    else{
        arr[front]=-1;
        front++;
    }
  }
};