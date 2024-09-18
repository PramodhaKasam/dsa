// Insertion in a doubly linked list at 1) beginning
                                        // 2) end
                                        // 3) position specified at   
                                        // 4 ) position specified after
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void CreateList(int n)
{
    struct node *temp, *newnode;
    head =0;
    for(int i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d:", i+1);
        scanf("%d", &newnode ->data);
        newnode ->prev = 0;
        newnode ->next = 0;
        if(head == 0)
        {
            temp = head = newnode;
        }
        else{
           temp ->next = newnode;
           newnode ->prev = temp;
           temp = newnode;
        }
    }
}

void Display()
{
    struct node *temp;
    temp = head;
    while(temp != 0)
    {
        printf("%d ", temp ->data);
        temp = temp ->next;
    }
}

void InsertAtBeginning()
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at the beginning:");
    scanf("%d",&newnode ->data);
    newnode -> next = head;
    head->prev = newnode;
    newnode ->prev = 0;
    head = newnode;
}

void InsertAtEnd()
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    printf("\nEnter the value to be inserted at the end:");
    scanf("%d", &newnode -> data);
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = 0;
}

void InsertAtSpecified()
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i= 1;
    int n;
    printf("\nEnter the position to insert at:");
    scanf("%d", &n);
    if(n != 0)
    {
        printf("Enter the value to be inserted at the position %d:", n);
        scanf("%d", &newnode -> data);
        while(i != n-1)
        {
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        newnode -> prev = temp;
        temp -> next -> prev = newnode;
        temp -> next = newnode;
    }
    else{
        InsertAtBeginning();
    }
    
}

void InsertAfterSpecified()
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i= 1;
    int n;
    printf("\nEnter the position to insert after:");
    scanf("%d", &n);
    printf("Enter the value to be inserted at the position %d:", n);
    scanf("%d", &newnode -> data);
    while(i != n)
    {
        temp = temp -> next;
        i++;
    }
    if( temp -> next == 0)
    {
        newnode ->prev = temp;
        temp -> next = newnode;
        newnode -> next = 0;
    }
    else{
        newnode -> next = temp -> next;
        newnode -> prev = temp;
        temp -> next -> prev = newnode;
        temp -> next = newnode;
    }
}

int main() {
    int n;
    printf("Enter the size of doubly linked list:");
    scanf("%d", &n);
    CreateList(n);
    Display();
    InsertAtBeginning();
    Display();
    InsertAtEnd();
    Display();
    InsertAtSpecified();
    Display();
    InsertAfterSpecified();
    Display();
    return 0;
}
