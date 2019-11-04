#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int* insertionSort(int* arr, int arraySize){

	int i, j, key, temp = 0;

	for (i = 1; i < arraySize; i++){

		key = arr[i];
		
		j = i;

		while (j > 0 && arr[j - 1] > key){//conditional: swap while the right index is less than the left index
			temp = arr[j];		 //saves value of right index
			arr[j] = arr[j - 1]; //change the right index to the left index
			arr[j - 1] = temp;   //make the left index be the temp
			j--;				 //increments downward to compare that the entire array is sorted on the left side
		}

	}
	return arr;
}

int* choose(int* arr, int arraySize){

	//Array size less than 10 will be sorted via Insertion sort
	if (arraySize < 10){
		insertionSort(arr, arraySize);
	}
	//Larger array size's will be sorted via Merge sort
	else{

		int firstHalf, secondHalf = 0;
		int i, j, k = 0;
		int* left, * right = NULL;

		//new empty array which will be used for the completely sorted array
		int* sorted = new int[arraySize];

		//first firstHalf of the array
		firstHalf = (arraySize / 2);

		//second firstHalf of the array
		secondHalf = arraySize - firstHalf;

		//Recursively sorts the left/right half via Insertion sort
		left = choose(arr, firstHalf);
		right = choose(arr + firstHalf, secondHalf);

		//left and right array are compared and placed into sorted array, placing smallest value in first
		while (i < firstHalf && j < secondHalf){
			if (left[i] < right[j]){
				sorted[k++] = left[i++];
			}
			else{
				sorted[k++] = right[j++];
			}
		}

		//if left is already filled within the sorted array, remaining values of the right array are filled in
		while (i == firstHalf && j < secondHalf){
			sorted[k++] = right[j++];
		}
		
		//if the right array is already filled within the sorted array, remaining values of the left array are filled in
		while (i < firstHalf && j == secondHalf){
			sorted[k++] = left[i++];
		}

		//fills the initial array with the completely sorted array
		for (i = 0; i < arraySize; i++)
			arr[i] = sorted[i];
	}
	return arr;
}

int main(int argc, char** argv){

	int* Sequence;
	int arraySize;

	// Get the size of the sequence
	cout << "Array Size: ";
	cin >> arraySize;

	// Allocate enough memory to store "arraySize" integers
	Sequence = new int[arraySize];

	cout << "Fill array with " << arraySize << " numbers: " << endl;

	// Read in the sequence
	for (int i = 0; i < arraySize; i++)
		cin >> Sequence[i];

	// Run your algorithms to manipulate the elements in Sequence
	choose(Sequence, arraySize);

	// Output the result
	cout << "Sorted Array:\n";
	for (int i = 0; i < arraySize; i++)
		cout << Sequence[i] << " ";

	// Free allocated space
	delete[] Sequence;
}
