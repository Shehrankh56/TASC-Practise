#include<bits/stdc++.h>
using namespace std;

class minStack{
    public:
    vector<pair<int,int>>st;
    minStack(){
        //constructor
    }

    void push(int val){
        if(st.empty()){
            pair<int,int>p;
            p.first=val;
            p.second=val;

            st.push_back(p);
        }else{
            pair<int,int>p;
            p.first=val;
            int prevMin=st.back().second;
            p.second=min(prevMin, val);

        }
    }
    void pop() {
    if (!st.empty()) {
        st.pop_back();
    } else {
        cout << "Stack Underflow: Cannot pop from an empty stack!" << endl;
    }
}


    int top(){
        pair<int,int>p = st.back();
        return p.first;
    }
    int getMin(){
        pair<int, int>p= st.back();
        return p.second;
    }

};

int main() {
    minStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top: " << s.top() << endl;         // Should print 2
    cout << "Min: " << s.getMin() << endl;      // Should print 2

    s.pop();
    cout << "Top after pop: " << s.top() << endl;    // Should print 7
    cout << "Min after pop: " << s.getMin() << endl; // Should print 3

    s.pop();
    s.pop();
    cout << "Min now: " << s.getMin() << endl;       // Should print 5

    return 0;
}