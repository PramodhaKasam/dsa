// Implementation of a doubly linked list
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

int main() {
    int n;
    printf("Enter the size of doubly linked list:");
    scanf("%d", &n);
    CreateList(n);
    Display(n);
    return 0;
}
