#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

// Function to heapify a subtree rooted with the given index
void heapify(int array[], int currentIndex, int size) {
    int smallestIndex = currentIndex;
    int leftChildIndex = 2 * currentIndex;
    int rightChildIndex = 2 * currentIndex + 1;

    // Compare with left child
    if (leftChildIndex <= size && array[leftChildIndex] < array[smallestIndex])
        smallestIndex = leftChildIndex;

    // Compare with right child
    if (rightChildIndex <= size && array[rightChildIndex] < array[smallestIndex])
        smallestIndex = rightChildIndex;

    // If the smallest index is not the current index, swap and recursively heapify
    if (currentIndex != smallestIndex) {
        swap(array[currentIndex], array[smallestIndex]);
        heapify(array, smallestIndex, size);
    }
}

// Function to build a min-heap
void buildMinHeap(int array[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(array, i, size);
    }
}

// Function to extract the minimum element from the heap
int extractMin(int array[], int &size) {
    int minValue = array[1];
    swap(array[1], array[size]);
    size--;
    heapify(array, 1, size);
    return minValue;
}

// Function to insert a new element into the heap
void insert(int array[], int &size, int value) {
    size++;
    array[size] = value;
    int currentIndex = size;
    while (currentIndex >= 2 && array[currentIndex / 2] > array[currentIndex]) {
        swap(array[currentIndex / 2], array[currentIndex]);
        currentIndex = currentIndex / 2;
    }
}

// Function to perform heap sort
void heapSort(int array[], int size) {
    buildMinHeap(array, size);
    for (int i = size; i > 1; i--) {
        swap(array[i], array[1]);
        size--;
        heapify(array, 1, size);
    }
}

int main() {
    int array[MAX_SIZE] = {0};
    int n, product = 1, size = 0;

    // Input the size of the array
    cin >> n;

    // Input array elements
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
        size++;
    }

    // Output products of the smallest three elements after each insertion
    for (int i = 1; i <= n; i++) {
        if (i < 3)
            cout << -1 << endl;
        else {
            heapSort(array, i);
            product = 1;
            for (int k = 1; k <= 3; k++)
                product *= array[k];
            cout << product << endl;
        }
    }

    return 0;
}
