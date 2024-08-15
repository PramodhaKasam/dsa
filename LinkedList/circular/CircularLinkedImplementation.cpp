// Implementation of a circular linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        struct Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    };
};

void createList(Node** head, int n)
{
    *head = 0;
    for(int i=0; i<n; i++)
    {
       Node *temp, *newnode;
       int val;
       cout<<"Enter the data of the position "<<i+1<<" :";
       cin>>val;
       newnode = new Node(val);
       newnode -> next = *head;
       if(*head == 0)
       {
           *head = temp = newnode;
       }
       else{
           temp -> next = newnode;
           temp = temp -> next;
       }
    }
}

void Display(Node* head)
{
    Node *temp;
    temp = head;
    while(1)
    {
        cout<<temp-> data<<" ";
        temp = temp -> next;
        if(temp == head)
        {
            break;
        }
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cout<<"Enter the size of circular linked list:";
    cin>>n;
    createList(&head, n);
    Display(head);
    return 0;
}
