#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int* arr, int strt, int en){
    
    int pivot, i, j = 0;

    //Select pivot as the last element in the array
    pivot = arr[en];

    //start i at -1, before first index of the array, 0
    i = strt -1;  
	
    //j - iterates through entire array
    //i - index of smaller element
    //when an element in the array is smaller than the pivot, 
    //swap the values so that: 
    //smaller element is on the left of the pivot
    //larger elemen is on the right of the pivot
    for(j=strt; j<=en-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    //swaps pivot in between the partition sections
    swap(arr[i+1], arr[en]);
    
    return i+1;
}

void quickSort(int* arr, int strt, int en){

    if(strt < en) {
        //Calculates position in the array where everything to the left are the smaller values
        //and everything to the right are larger values
        int BREAKPOINT = partition(arr, strt, en);

        //quicksorts lower (left of breakpoint) half and upper (right of breakpoint) half of the array respectively
        quickSort(arr, strt, BREAKPOINT-1);
        quickSort(arr, BREAKPOINT+1, en);
    }
}

int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cout << "Array size: ";
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];

  cout << "Fill in array:" << endl;

  // Read in the sequence
  for ( int i=0; i<arraySize; i++)
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  quickSort(Sequence,0, arraySize-1);

  cout << "Sorted Array:" << endl;
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << " ";

  // Free allocated space
  delete[] Sequence;
  
}
