//Implementation
#include <bits/stdc++.h>
using namespace std;

int* arr;
int heapSize;
int maxSize;

void initMaxHeap(int totSize) {
    heapSize = 0;
    maxSize = totSize;
    arr = new int[totSize];
}

void MaxHeapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heapSize && arr[l] > arr[largest]) largest = l;
    if (r < heapSize && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

void insertKey(int x) {
    if (heapSize == maxSize) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void increaseKey(int i, int newVal) {
    arr[i] = newVal;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int removeMax() {
    if (heapSize <= 0) return INT_MIN;
    if (heapSize == 1) {
        heapSize--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;
    MaxHeapify(0);

    return root;
}

void deleteKey(int i) {
    increaseKey(i, INT_MAX);
    removeMax();
}

int getMax() {
    return arr[0];
}

int curSize() {
    return heapSize;
}

int main() {
    int n;
    cin>>n;
    initMaxHeap(n);

   for(int i=0; i<n; i++)
   {
       int t;
       cin>>t;
       insertKey(t);
   }

    cout << "The current size of the heap is " << curSize() << "\n";
    cout << "The current maximum element is " << getMax() << "\n";

    deleteKey(2);
    cout << "The current size of the heap after deletion is " << curSize() << "\n";

    insertKey(15);
    insertKey(5);
    cout << "The current size of the heap is " << curSize() << "\n";
    cout << "The current maximum element is " << getMax() << "\n";

    return 0;
}
