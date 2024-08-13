// To reverse a linked list by using loops
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void CreateList(int q)
{
    head = 0;
    struct node *temp, *newnode;
    for(int i=0; i<q; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data required:");
        scanf("%d", &newnode -> data);
        newnode -> next = 0;
        if(head == 0)
        {
            head =newnode;
            temp = newnode;
        }
        else{
            temp -> next = newnode;
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
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void ReverseList()
{
    struct node *temp, *nextnode, *prevnode;
    prevnode = 0;
    nextnode = temp = head;
    while(nextnode != 0)
    {
        nextnode = nextnode ->next;
        temp ->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    head = prevnode;
}

int main() {
   printf("Enter the size of data required:");
   int q;
   scanf("%d", &q);
   CreateList(q);
   Display();
   ReverseList();
   printf("\nLinked List after reversing:\n");
   Display();
   return 0;
}
