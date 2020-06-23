/*
 * C++ Program To Implement Radix Sort
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int countSort(int arr[][10],int brr[][10],int colm, int arrSize){

    int crr[4];

    for(int i = 0; i <= 3; i++)     //fills the counter array to 0
        crr[i] = 0;

    for(int j =0; j < arrSize; j++)
        crr[arr[j][colm]] = crr[arr[j][colm]] + 1;  //counts the # of occurrences for each #

    for(int i =1; i < 4; i++)
        crr[i] = crr[i] + crr[i-1];     //adds all occurrences up to an index

    for (int j = arrSize-1; j >= 0; j--){        //
        for(int z = 9; z >= 0; z--){
            brr[crr[arr[j][colm]]-1][z] = arr[j][z];    //copies into proper position into output array
        }
        crr[arr[j][colm]] = crr[arr[j][colm]]-1;        //decrements the counter of occurrences
    }
}


int radixSort(int arr[][10], int brr[][10] ,int arrSize){

    for(int i = 9; i >= 0; i--){
     countSort(arr,brr,i,arrSize);

     for(int j =0; j<arrSize; j++){
            for (int k=0; k< 10;k++){
                arr[j][k] = brr[j][k];  //copies a into b to change the starting point
            }

     }
    }
}


int main(){

    int arrSize;

    cin >> arrSize;

    int arr[arrSize][10];
    int brr[arrSize][10];

    for(int i =0; i<arrSize; i++){
        for (int j=0; j< 10;j++){
            cin >> arr[i][j];
            brr[i][j]= 88;           //fills brr with 0's so to avoid trash being filled in
        }
    }


    radixSort(arr,brr,arrSize);

    for(int i =0; i < arrSize; i++){
        for(int j =0; j< 10; j++){
         cout << brr[i][j] << ";";
        }
    cout << endl;
    }



}
