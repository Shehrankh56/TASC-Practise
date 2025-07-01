#include<iostream>
#include<stack>
using namespace std;
//creation of a stack 
int main()
{
stack<int>st;
//insertion
st.push(10);
st.push(20);
st.push(30);
st.push(40);
//size of a stack
cout<<" size of a stack is :"<< st.size()<<endl;

//remove of stack 
st.pop();
cout<<" size of a stack is :"<< st.size()<<endl;
st.pop();
cout<<" size of a stack is :"<< st.size()<<endl;
st.pop();
cout<<" size of a stack is :"<< st.size()<<endl;
cout<<st.top()<<endl;

// is empty
if(st.empty())
{
    cout<<"stack is empty"<<endl;
}
else{
    cout<<"stack is not empty"<<endl;
}


}