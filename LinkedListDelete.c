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

void DeleteAtBeginning()
{
    struct node *temp;
    temp = head;
    head = head -> next;
    free(temp);
}

void DeleteAtEnd()
{
    struct node *temp, *prevnode;
    temp = head;
    while(temp -> next != 0)
    {
        prevnode = temp;
        temp = temp -> next;
    }
    if(temp == head)
    {
        free(head);
    }
    else{
        free(temp);
        prevnode -> next = 0;
    }
}

void DeleteAtSpecified()
{
    printf("\nEnter the position to delete:");
    int pos;
    scanf("%d", &pos);
    struct node *temp, *prevnode;
    temp = head;
    int count = 1;
    while(count != pos)
    {
        prevnode = temp;
        temp = temp -> next;
        count++;
    }
    prevnode -> next = temp -> next;
    free(temp);
}

int main() {
   printf("Enter the size of data required:");
   int q;
   scanf("%d", &q);
   CreateList(q);
   Display();
   DeleteAtBeginning();
   printf("\nArray after deleting from the beginning:\n");
   Display();
   DeleteAtEnd();
   printf("\nArray after deleting from the end:\n");
   Display();
   DeleteAtSpecified();
   Display();
   return 0;
}
