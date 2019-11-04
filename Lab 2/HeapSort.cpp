#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void heapify(int arr[], int arraySize, int parent){

    int largest, left, right = 0;
    
    //largest is parent node
    largest = parent;

    //left child node
    left = 2 * parent + 1;

    //right child node
    right = 2 * parent + 2;

    //Checks to see if left child is larger than parent
    if (left < arraySize && arr[left] > arr[largest])
        largest = left;

    //Checks to see if right child is larger than parent
    if (right < arraySize && arr[right] > arr[largest])
        largest = right;

    //Continues until Max Heap is created
    if (largest != parent){
        swap(arr[parent], arr[largest]);
        heapify(arr, arraySize, largest);
    }
}

void HeapSort(int arr[], int arraySize){

    //Initially creates a max heap
    //i will truncate remainder of division
    //wiki (floor(n/2) - 1)
    for (int i = (arraySize/2) - 1; i >= 0; i--)
        heapify(arr, arraySize, i);

    //Swap the root node with last node
    //recreate Max Heap with reduced arraySize
    for (int i = arraySize - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char **argv){

    int *Sequence;
    int arraySize;

    // Get the size of the sequence
    cout << "Array size: ";
    cin >> arraySize;

    // Allocate enough memory to store "arraySize" integers
    Sequence = new int[arraySize];

    cout << "Fill in array:" << endl;

    // Read in the sequence
    for (int i = 0; i < arraySize; i++)
        cin >> Sequence[i];

    // Run your algorithms to manipulate the elements in Sequence
    HeapSort(Sequence, arraySize);

    cout << "Sorted Array:" << endl;
    // Output the result
    for (int i = 0; i < arraySize; i++)
        cout << Sequence[i] << " ";

    // Free allocated space
    delete[] Sequence;
}
