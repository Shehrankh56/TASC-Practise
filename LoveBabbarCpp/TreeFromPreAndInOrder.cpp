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


int searchInInorder(int inOrder[], int size, int target){
    for(int i=0; i< size; i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    return -1;
}

void createMapping(int inOrder[], int size, unordered_map<int,int>& valueToIndex){
    for(int i=0; i< size; i++){
        int element=inOrder[i];
        int index=i;
        valueToIndex[element]=index;
    }
}
Node* constructTreeFromPreAndInorder(unordered_map<int,int>& valueToIndex, int preOrder[], int& preIndex, int size, int inOrder[], int inOrderStart, int inOrderEnd){

    //Base Case
    if(preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 case me solve krunga baki recursion krega 

    int element = preOrder[preIndex];
    preIndex++;

    Node* root = new Node(element);

    int position=valueToIndex[element];

    root->left = constructTreeFromPreAndInorder(valueToIndex,preOrder, preIndex, size, inOrder, inOrderStart, position-1);
    root->right = constructTreeFromPreAndInorder(valueToIndex, preOrder, preIndex, size, inOrder, position+1, inOrderEnd);

    return root;
}

int main(){

    int preOrder[]={2,8,10,6,4,12};
    int preIndex=0;
    int size=6;
    int inOrder[]={10,8,6,2,4,12};
    int inOrderStart=0;
    int inOrderEnd=size-1;

    unordered_map<int,int>valueToIndex;
    createMapping(inOrder,size , valueToIndex);

    Node* root = constructTreeFromPreAndInorder(valueToIndex, preOrder, preIndex, size, inOrder, inOrderStart, inOrderEnd);
    cout << "Printing Entire Tree:"<<endl;
    LevelOrderTraversal(root);
    return 0;

}