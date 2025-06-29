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

void preOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    //N
    cout << root->data << " ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);

}

void InorderTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    //L
    InorderTraversal(root->left);
    //N
    cout << root->data << " ";
    //R
    InorderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return ;

    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->data << " ";
}

int main(){

    Node* root=createTree();

    cout << "Pre-Order Traversal: "<<endl;
    preOrderTraversal(root);

    cout << endl;

    cout << "Inorder Traversal:"<<endl;
    InorderTraversal(root);

    cout << endl;
    
    cout << "Post Order Traversal"<<endl;
    postOrderTraversal(root);
}