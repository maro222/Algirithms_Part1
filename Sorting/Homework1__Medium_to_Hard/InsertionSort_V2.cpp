#include "../Sorting.h"

//descending
void InsertionSort_V2(int arr[], int len){

    // shifting by swapping
    for(int i = 0; i < len; i++)
        for(int j = i + 1; j > 0 && arr[j] > arr[j-1]; j--)
            swap(arr[j], arr[j-1]);
}

// this code is readable but slower(if swapping is internally 3 steps)
// v1 is more efficient than that version

