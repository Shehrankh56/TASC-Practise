#include<iostream>
#include<stack>
using namespace std;

int solve(stack<int>& st, int &pos , int &ans)
{
    if(pos==1)
    {
        ans=st.top();
        return ans ;
    }
    pos--;
    int temp=st.top();
    st.pop();

    solve(st,pos,ans);

    st.push(temp);

}
int MiddleElement(stack<int>& st)
{
    int size=st.size();
    if(st.empty())
    {
        cout<<"UnderFlow condition"<<endl;
        return -1;

    }
    else{
        if(size%2==0)
        {
            pos=size/2;
        }
        else{
            pos=size/2+1;
        }
        int ans=-1;
        solve(st,pos,ans);
        return ans;

    }
    
}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    
   cout<<"Middle Element is :"<< MiddleElement(st)<< endl;
}