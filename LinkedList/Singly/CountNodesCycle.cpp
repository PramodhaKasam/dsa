//Count number of nodes
// in loop in a linked list if loop is present
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* node) {
    int count = 1;
    struct Node* curr = node;
    while (curr->next != node) {
        count++;
        curr = curr->next;
    }
    return count;
}

int countNodesInLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return countNodes(slow);
    }
    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head->next;
    printf("%d\n", countNodesInLoop(head));

    return 0;
}
