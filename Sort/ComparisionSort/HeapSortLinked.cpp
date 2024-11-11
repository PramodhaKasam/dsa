//Sort a linked list using heap sort

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 7

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void heapify(Node** arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->data > arr[largest]->data) {
        largest = left;
    }
    if (right < n && arr[right]->data > arr[largest]->data) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i]->data, arr[largest]->data);
        heapify(arr, n, largest);
    }
}

void sortArray(Node** arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0]->data, arr[i]->data);
        heapify(arr, i, 0);
    }
}

void heapsort(Node* head) {
    Node* temp = head;
    Node** arr = new Node*[SIZE];
    int i = 0;

    while (temp != nullptr && i < SIZE) {
        arr[i++] = temp;
        temp = temp->next;
    }

    sortArray(arr, SIZE);

    cout << "LinkedList after sorting: ";
    printList(head);

    delete[] arr;
}

Node* createLinkedList() {
    srand(time(nullptr));
    Node* head = new Node(rand() % 101);
    Node* current = head;

    for (int i = 1; i < SIZE; i++) {
        current->next = new Node(rand() % 101);
        current = current->next;
    }

    cout << "LinkedList before sorting: ";
    printList(head);
    return head;
}

int main() {
    Node* head = createLinkedList();
    heapsort(head);

    return 0;
}
