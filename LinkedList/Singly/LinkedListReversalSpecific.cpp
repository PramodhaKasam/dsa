// Reversal of a singly linked list when two positions are specified for reversal
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
    for(int i=0; i<n; i++)
    {
        Node *temp, *newnode;
        int data;
        cout<<"Enter the data of the position "<<i+1<<":";
        cin>>data;
        newnode = new Node(data);
        newnode -> next = 0;
        if(*head == NULL)
        {
            *head = temp = newnode;
        }
        else{
            temp-> next = newnode;
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

void ReversalSpecified(Node** head, int i, int j)
{
    Node *temp = *head;
    Node *nextnode, *nnode;
    int count =1;
    if(i != 1)
    {
        while(count != i-1)
        {
            temp = temp -> next;
            count++;
        }
        Node *firstNode = temp;
        Node *secondNode = temp ->next;
        temp = temp -> next;
        nextnode = temp -> next;
        count = i;
        while(count != j)
        {
            nnode = nextnode -> next;
            nextnode -> next = temp;
            temp = nextnode;
            nextnode = nnode;
            count++;
        }
        secondNode ->next = nextnode;
        firstNode -> next = temp;
    }
    else
    {
        *head = temp;
         count = i;
         nextnode 
        while(count != j)
        {
            nnode = nextnode -> next;
            nextnode -> next = temp;
            temp = nextnode;
            nextnode = nnode;
            count++;
        }
         (*head)->next = nextnode;
         *head = temp;
    }
    
}

int main()
{
    Node *head = NULL;
    int n;
    cout<<"Enter the size of doubly linked list:";
    cin>>n;
    createList(&head, n);
    Display(head);
    int a, b;
    cout<<"\nEnter the positions to perform the reversal:\n";
    cin>>a>>b;
    ReversalSpecified(&head, a, b);
    Display(head);
    return 0;
}
