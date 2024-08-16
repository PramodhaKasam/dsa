// Implementation of Doubly circulsr linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int val)
    {
        data= val;
        next = nullptr;
        prev = nullptr;
    };
};

void createList(Node** head, int n)
{
    Node* temp;
    *head = 0;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the data for the position "<<i+1<<" : ";
        int val;
        cin>>val;
        Node *newnode = new Node(val);
        newnode -> next = *head;
        if(*head == 0)
        {
            *head = temp = newnode;
            (*head) -> next = *head;
            (*head) -> prev = *head;
        }
        else{
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
        }
       ( *head) -> prev = newnode;
    }
}

void Display(Node* head)
{
    Node* temp = head;
    while(1)
    {
        cout<< temp ->data<<" ";
        temp = temp -> next;
        if(temp == head)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of Doubly linked list:";
    cin>>n;
    Node *head;
    createList(&head, n);
    Display(head);
    return 0;
}
