#include <stdio.h>
#include <stdlib.h>

struct Node {
    int* arr;       
    struct Node* next; 
};


struct Stack {
    int n;           
    struct Node* linkTop; 
    int stackTop;     
};

struct Node* createNode(int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->arr = (int*)malloc(n * sizeof(int));
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->n = size;
    stack->linkTop = NULL;
    stack->stackTop = -1;
    return stack;
}

void push(struct Stack* stack, int x) {
    if (stack->linkTop == NULL || stack->stackTop == stack->n - 1) {
        struct Node* newNode = createNode(stack->n);
        newNode->next = stack->linkTop;
        stack->linkTop = newNode;
        stack->stackTop = -1; 
    }
    stack->linkTop->arr[++stack->stackTop] = x;
}

int pop(struct Stack* stack) {
    if (stack->linkTop == NULL) { 
        printf("Stack Underflow\n");
        return -1;
    }
    int topElement = stack->linkTop->arr[stack->stackTop--]; 
    if (stack->stackTop == -1) {
        struct Node* temp = stack->linkTop;
        stack->linkTop = stack->linkTop->next;
        free(temp->arr);
        free(temp);
        if (stack->linkTop) stack->stackTop = stack->n - 1; 
    }
    return topElement;
}

int elements(struct Stack* stack) {
    int count = 0;
    struct Node* temp = stack->linkTop;
    int currentTop = stack->stackTop;

    while (temp != NULL) {
        count += (temp == stack->linkTop) ? currentTop + 1 : stack->n;
        temp = temp->next;
        currentTop = stack->n - 1;
    }
    return count;
}

void printStack(struct Stack* stack) {
    struct Node* temp = stack->linkTop;
    int currentTop = stack->stackTop;

    while (temp != NULL) {
        for (int i = currentTop; i >= 0; i--)
            printf("%d ", temp->arr[i]);
        temp = temp->next;
        currentTop = stack->n - 1;
    }
    printf("\n");
}

void freeStack(struct Stack* stack) {
    struct Node* temp = stack->linkTop;
    while (temp != NULL) {
        struct Node* toFree = temp;
        temp = temp->next;
        free(toFree->arr);
        free(toFree);
    }
    free(stack);
}

int main() {
    int size;
    printf("Enter the size of each node's array: ");
    scanf("%d", &size);

    struct Stack* stack = createStack(size);

   
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);  

    printf("Current stack elements: ");
    printStack(stack);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    printf("Current stack elements after popping: ");
    printStack(stack);

    printf("Total elements in stack: %d\n", elements(stack));

 
    freeStack(stack);
    return 0;
}

//Consider a scenario where we want to build a stack which is implemented using array but at the same time
//when the “stack overflow” condition arises, it can add another array of the same size. This is going to be
//a combination of array and list implementations of a stack. To implement this stack you have to do the
//following:
//1. You have to define a structure to define a node of a singly linked list with only difference that instead
//of a single integer, each node will hold an array of integers. The size of the array n should be user
//defined. (5)
//2. Your stack should have two variables to keep track of top, 1) link top, 2) stack top. The stack top
//variable will keep track of the location of top element and the link top variable will point to the list
//node on which the top element resides.
//3. expand push(S1, x): This operation will push an element at the top of the stack like normal stack. If
//the stack is full, a new list node will be added to the front of the list with same array size given by the
//user. Then you have to insert x in the new node. You have to update your top variables accordingly.
//(10)
//4. shrink pop(S1): This operation will extract the top element from the stack and return that value.
//When the last element of a node is extracted, the function will free that node of the list and update
//all the top variables accordingly. The “stack underflow” condition occurs when the link top points to
//NULL. (10)
//5. elements(S1): This function will return the total number of elements available in the stack. You are
//not allowed to store this number separately. (10)
//6. print stack(S1): This function will print all the elements of the stack.
