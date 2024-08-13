// Deletion of node from diubly linked list at 1) beginning
//                                             2) end
//                                             3) position specified
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
    };
};

void CreateList(int n, Node** head)
{
    Node *temp, *newnode;
    for(int i=0; i<n; i++)
    {
        int val;
        cout<<"Enter the value at the position "<< i+1<<":";
        cin>>val;
        newnode = new Node(val);
        newnode -> next = 0;
        newnode -> prev = 0;
        if(*head == 0)
        {
            *head = temp = newnode;
        }
        else{
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
        }
    }
}

void Display(Node** head)
{
    Node *temp = *head;
    while(temp != 0)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

void DeleteAtBeginning(Node** head)
{
    Node *temp = *head;
    *head = temp -> next;
    temp -> next -> prev = *head;
    delete temp;
}

void DeleteAtEnd(Node** head)
{
    Node *temp = *head;
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    delete temp;
}

void DeleteAtSpecified(int size, int n, Node** head)
{
    Node *temp = *head;
    int count = 1;
    if(n == 0)
    {
        DeleteAtBeginning(head);
    }
    else if(n > size)
    {
        cout<<"Error: not possible!\n";
    }
    else if(n == size)
    {
        DeleteAtEnd(head);
    }
    else{
        while(count != n)
        {
            temp = temp -> next;
            count++;
        }
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        delete temp;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the doubly linked list:";
    cin>>n;
    Node *head = NULL;
    CreateList(n, &head);
    Display(&head);
    DeleteAtBeginning(&head);
    cout<<"\nDoubly linked list after deletion from the beginning:\n";
    Display(&head);
    DeleteAtEnd(&head);
    cout<<"\nDoubly linked list after deletion from the end:\n";
    Display(&head);
    cout<<"\nEnter the position to delete from:";
    int pos;
    cin>>pos;
    DeleteAtSpecified(n-2, pos, &head);
    cout<<"Doubly linked list after deletion from the position :\n";
    Display(&head);
    return 0;
}
