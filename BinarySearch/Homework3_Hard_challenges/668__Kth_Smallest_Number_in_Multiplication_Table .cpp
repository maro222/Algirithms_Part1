#include "../BinarySearch.h"

/**
 * findKthNumber - find the kth element in sorted multiplication matrix
 * @param m : number of rows
 * @param n : number of columns
 * @param k : index of returned value
 * @return : integer on success
 */

/*
 *Approach #1: Brute Force [Memory Limit Exceeded]
 *
 *Intuition and Algorithm
 *Create the multiplication table and sort it, then take the kth element.
 */
int findKthNumber(int m, int n, int k){
    vector<int> flat(n*m, 0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            flat[i * n + j] = (i + 1) * (j + 1);  // flatten array==> (row * clos + col)

    sort(flat.begin(), flat.end());
    return (flat[k - 1]);
}


                                      /* Approach 2: binary search*/  // O(nlgn)
/*
 * intuition:
 * So Binary search will come here i.e. binary search on answer because we know here is monotonicity
 * because answer is in sorted order(we have to pick elements from sorted elements) ; Also here if x satisfies count_less,
 * then any value larger than x can satisfy.
 * So if we want to find the kth smallest number we can do binary search on answer
 * and guess a mid if k numbers are <= mid that means it can be our answer .
 *
 * General Approach:
 *         So our search space is from 1 (least number) to n*m (maximum that can be formed in multiplication table).
 *          Now our mid will be the guess for our answer, and we have check if k numbers are <= mid or not .
 *          this can be done using a count_less function:
 *          For count_less function here is important observation that numbers in a row are multiples of their row (e.g 2 4 6 8 )
 *          so if we have to check where the number lies in a row we can just do num/row_no.
 *          that will give how many numbers it is greater than
 *          e.g. row 2 is 2 4 6 8 so if mid = 6 we do 6/2 =3 so there are 3 numbers <=6 that are actually 2,4,6.
 */

// the number of elements less than specific value in specific row
//            ==>   any element * row <= value   ==>   value / row ==  # of elements less than value
//  we choose the minimum between (the # of elements less than value && cols) to
//  avoid counting numbers out of boundaries

/**
 * count_less - count the number of elements smaller than value
 * @param m : # or rows
 * @param n : # of columns
 * @param value : the value
 * @return : the number of smaller elements
 */
int count_less(int m, int n, int value){  //O(n)
    int count = 0;
    for (int row = 1; row <= m; row++)
        count += min(value / row, n);
    return (count);
}
/*
 *  kth = index + 1
 *  the kth element in sorted array has (kth - 1) elements that is <= kth element
 *  So, when we count the number of elements less than certain value , it returns the index of this value
 *
 * # of elements <= value = index of this value
 *
 * matrix:
 *   1  2  3
 *   2  4  6
 *   3  6  9
 *   lets assume the k is 8th:
 *   if we send value 7 , then the # number of elements <= 7 is 8 elements, then it's the 8th element
 *   ,but we want smallest kth element(that by the way will be in multiplication matrix)
 *
 *   why we binary search for smallest? ==> because of nature of multiplication matrix:
 *   when we search for 7th elements we find that elements 6, 7, 8 achieve this kth,
 *   but we are sure that 6 (the smallest) is in the matrix
 *   1 2 3
 *   2 4 6
 *   3 6 9
 *   if we search for kth element , the smallest element that achieves this kth is for sure in the matrix
 *   unlike the other larger elements that achieve the kth
 */

/**
 * findKthNumber - find the kth element in sorted multiplication matrix
 * @param m : number of rows
 * @param n : number of columns
 * @param k : index of returned value
 * @return : integer on success
 */
int findKthNumber_2(int m, int n, int k){  //O(log n)
    int start = 1, end = n * m;  // boundaries of elements
    int kth = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if (count_less(m, n, mid) < k) // not enough
            start = mid + 1;
        else
            end = mid - 1; kth = mid;
    }
    return (kth);
}
