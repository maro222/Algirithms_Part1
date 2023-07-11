#include "Sorting.h"

void SelectionSort(int arr[], int len){
    int min_idx;
    for(int i = 0; i < len - 2; i++)
    {
        min_idx = i;
        for(int j = i + 1; j < len - 1; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        //swapping
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/*
 *    General idea:
 * We start selection sort by scanning the entire given list to find its smallest element
 * and exchange it with the first element, putting the smallest element in its final
 * position in the sorted list. Then we scan the list, starting with the second element,
 * to find the smallest among the last n − 1 elements and exchange it with the second
 * element, putting the second_smallest element in its final position
 *
 * After n − 1 passes, the list is sorted.
 *
 * The basic operation of the algorithm is the key comparison A[j] < A[min]
 *
 * The number of key comparisons in this algorithm obviously depends on the
 *   nature of the input
 *
 * selection sort is a ceta (n2) algorithm on all inputs. Note, however, that the
 * number of key swaps is only ceta (n), or, more precisely, n − 1 (one for each repetition
 * of the i loop)
 *
 * Selection sort is a comparison-based algorithms as We compare to get the minimum
 * is in-place algorithm [ O(1) ]
 * not used in online processing ___ It sorted subarray never changes. We just pick the minimum from what is next.
 * not Adaptive ___  the processing flow is same regardless the nature of input data
 * best case = worst case = (n2)
 * not stable ___ The swap operation corrupts the order of the other elements.
 *            ___  Assume input is integers: 5A 3 4 5B 2 6 8. After a single step it will be 2 3 4 5B 5A 6 8. The value 5 order is now corrupted.
 *            ___ we can make it stable by Use the shift idea in the insertion sort. But this is making it more_slower!!
 *
 * Insertion sort scans backwards from the current key, while selection sort scans forwards
 *
 * After the k-th step:
 * in selection sort,     the first k elements are the minimum in the whole array and won't be changed,
 * but in insertion sort, the first k elements are just a sorted subarray that may change in the next steps
 *
 * In general, Insertion sort is more efficient compared to selection sort
 *
 */
