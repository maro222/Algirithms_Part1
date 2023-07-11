#include "Sorting.h"

void CountSort(int arr[], int len){
    //first : we find the maximum value in arr
    int maxSize = arr[0];
    for(int i = 1; i < len; i++)
    {
        if(arr[i] > maxSize)
            maxSize = arr[i];
    }

    // second : we declare a vector of size = (maximum value of arr + 1) and
    // we initialize it with zeros(default any way) ===> we declare a Frequency array
    vector<int> count(maxSize + 1);  //Zeros

    // we count the number of values in arr occurs
    for(int i = 0; i < len; i++)
        count[arr[i]] += 1 ;

    //fourth: we loop on each count(count[i]) and
    // assign the values it occurs to arr count[i] times (with incremental index)
    int idx = 0;
    for(int i = 0; i <= maxSize; i++)
        for(int j = 0; j < count[i]; i++, idx++)
            arr[idx] = i;
}



/*
 * complexity space = O(k) space (frequency array) where
 *                k is the maximum value in arr
 *
 * complexity time = O(K + N)  where
 *                k = the maximum value of arr and
 *                n = the numbers of array elements
 *                clearly we loop k steps , but the number of internal looping is the
 *                number of elements in array
 *
 * worst case = O(N2)  on distinct elements array
 * best case  = O(N)   on similar elements array (array of one repeated element)
 *
 * not stable   ___   as we lost values by depending on frequency array
 * not adaptive ___  the processing flow is same regardless the nature of input data
 * not practical for online processing ___ we have to compute the whole output array from begginning
 * mot in_place implementation   ___ as it requires extra spase
 *
 *
 */
