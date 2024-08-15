//     Deletion in a circular linked list at 1) beginning
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

void DeleteAtBeginning(Node** head)
{
    Node *temp= *head;
    while(temp -> next != *head)
    {
        temp = temp -> next;
    }
    Node *start = *head;
    *head = (*head) -> next;
    temp -> next = *head;
    delete start;
}

void DeleteAtEnd(Node* head)
{
    Node* temp = head;
    while(temp -> next -> next != head)
    {
        temp = temp -> next;
    }
    Node *end = temp -> next;
    delete end;
    temp -> next = head;
}

void DeleteAtSpecified(Node** head, int x)
{
    int n;
    cout<<"Enter the position to delete:";
    cin>>n;
    if(n <= 0 || n > x)
    {
        cout<<"Invalid\n";
    }
    else if( n == 1)
    {
        DeleteAtBeginning(head);
    }
    else if(n == x)
    {
        DeleteAtEnd(*head);
    }
    else{
        Node* temp = *head;
        int count = 1;
        while(count != n-1)
        {
            temp = temp -> next;
            count++;
        }
        Node *start = temp ->next;
        temp -> next = temp -> next -> next;
        delete start;
        cout<<"Linked list after deleting from the position "<<n<<" :\n";
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
    DeleteAtBeginning(&head);
    cout<<"Linked list after deleting from the beginning:\n";
    n--;
    Display(head);
    DeleteAtEnd(head);
    cout<<"Linked list after deleting from the end:\n";
    n--;
    Display(head);
    DeleteAtSpecified(&head, n);
    Display(head);
    return 0;
}
