// Reversal of a doubly linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        struct Node *next;
        struct Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    };
};

void createList(Node** head, int n)
{
    for(int i=0; i<n; i++)
    {
        Node *temp, *newnode;
        int data;
        cout<<"Enter the data of the position "<<i+1<<":";
        cin>>data;
        newnode = new Node(data);
        newnode -> next = 0;
        newnode -> prev = 0;
        if(*head == NULL)
        {
            *head = temp = newnode;
        }
        else{
            temp-> next = newnode;
            newnode ->prev = temp;
            temp = temp -> next;
        }
    }
}

void Display(Node* head)
{
    Node *temp;
    temp = head;
    while(temp != 0)
    {
        cout<<temp-> data<<" ";
        temp = temp -> next;
    }
}

void Reversal(Node** head)
{
    Node *temp = *head;
    Node *nextnode;
    while(temp->next != 0)
    {
        nextnode = temp->next;
        temp -> next = temp -> prev;
        temp -> prev = nextnode;
        temp = nextnode;
    }
    temp -> next = temp->prev;
    temp->prev = NULL;
    *head = temp;
}

int main()
{
    Node *head = NULL;
    int n;
    cout<<"Enter the size of doubly linked list:";
    cin>>n;
    createList(&head, n);
    Display(head);
    Reversal(&head);
    cout<<"\nDoubly linked list after reversal:\n";
    Display(head);
    return 0;
}
