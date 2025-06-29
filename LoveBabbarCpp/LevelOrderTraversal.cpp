#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *createTree(){

    cout << "Enter the Node :"<< endl;
    int data;
    cin >> data;
    if(data == -1) return NULL;

    Node* root= new Node(data);

    root->left=createTree();

    root->right=createTree();

    return root;

}

void LevelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 1){
        Node* front=q.front();// idhar glti kri thi , Node* ki  jagah int leliya tha 
        q.pop();

        if(front == NULL){
            cout<< endl;
            q.push(NULL);
        }else{
            //valide case hai
            cout<< front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}


int main(){

    Node* root=createTree();
    LevelOrderTraversal(root);
    
}