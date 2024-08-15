//    Insertion of a circular linked list at 1) beginning
                                        //   2) end
                                        //   3) specified position
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
    cout<<endl;
}

void InsertAtBeginning(Node** head)
{
    int val;
    cout<<"Enter the data to insert at the beginning:";
    cin>>val;
    Node *newnode = new Node(val);
    Node *temp= *head;
    while(temp -> next != *head)
    {
        temp = temp -> next;
    }
    newnode -> next = (*head);
    *head = newnode;
    temp -> next = *head;
}

void InsertAtEnd(Node* head)
{
    int val;
    cout<<"Enter the data to insert at the end:";
    cin>>val;
    Node *newnode = new Node(val);
    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
}

void InsertAtSpecified(Node** head, int x)
{
    int n;
    cout<<"Enter the position to insert:";
    cin>>n;
    if(n <= 0 || n > x)
    {
        cout<<"Invalid\n";
    }
    else if( n == 1)
    {
        InsertAtBeginning(head);
    }
    else if(n == x)
    {
        InsertAtEnd(*head);
    }
    else{
        int val;
        cout<<"Enter the data to insert at the position "<<n<<" :";
        cin>>val;
        Node *newnode = new Node(val);
        Node* temp = *head;
        int count = 1;
        while(count != n-1)
        {
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
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
    InsertAtBeginning(&head);
    n++;
    Display(head);
    InsertAtEnd(head);
    n++;
    Display(head);
    InsertAtSpecified(&head, n);
    Display(head);
    return 0;
}
