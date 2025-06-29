#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data=data;
        this->next=NULL;

    }

};

int CountLenLL(Node* head)
{
    
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
       count++; 
       temp=temp->next;
    }
    return count;
}
int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fivth = new Node(50);

    Node* head=first;
    first -> next=second;
    second -> next=third;
    third -> next=fourth;
    fourth -> next=fivth;
    
    cout<<"lenght of linked list is:"<<CountLenLL(head)<<endl;

}