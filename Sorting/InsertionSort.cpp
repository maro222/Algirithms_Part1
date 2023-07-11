#include "Sorting.h"

void InsertionSort(int arr[], int len){
    int v, j;
    for (int i = 1; i < len - 1; i++){
        v = arr[i];
        j = i - 1;

        while(j >= 0 && v < arr[j])
        {
            //shifting
            arr[j+1] = arr[j];
            arr[j] = v;
            j--;
        }
    }
}

/*
 * Following the technique’s idea,
 * we assume that the smaller problem of sorting the array A[0...n − 2] has already been solved to give
 * us a sorted array of size n − 1: A[0] ≤ ... ≤ A[n − 2]. How can we take advantage
 * of this solution to the smaller problem to get a solution to the original problem
 * by taking into account the element A[n − 1]? Obviously, all we need is to find an
 * appropriate position for A[n − 1] among the sorted elements and insert it there.
 * This is usually done by scanning the sorted subarray from right to left until the
 * first element smaller than or equal to A[n − 1] is encountered to insert A[n − 1]
 * right after that element. The resulting algorithm is called straight insertion sort
 * or simply insertion sort.
 *
 * Though insertion sort is clearly based on a recursive idea, it is more efficient
 *   to implement this algorithm bottom up, i.e., iteratively.
 *
 * The basic operation of the algorithm is the key comparison A[j ] > v
 *
 * The number of key comparisons in this algorithm obviously depends on the
 *   nature of the input
 *
 *   In other words, the worst-case input is an array of strictly decreasing values. The
 *     number of key comparisons for such an input is
 *     C_worst(n) ∈ (n2)
 *
 *
 * In the best case, the comparison A[j ] > v is executed only once on every
 *   iteration of the outer loop. (It happens if and only if A[i − 1] ≤ A[i] for every
 *   i = 1,...,n − 1,)  i.e., if the input array is already sorted in non-decreasing order
 *   C_best(n)  ∈ (n)
 *
 *     Adaptive
 *     stable
 *
 *
 *   Insertion sort scans backwards from the current key, while selection sort scans forwards
 *
 * After the k-th step:
 * in selection sort,     the first k elements are the minimum in the whole array and won't be changed,
 * but in insertion sort, the first k elements are just a sorted subarray that may change in the next steps
 *
 * In general, Insertion sort is more efficient compared to selection sort
 */

