#include "../BinarySearch.h"

/**
 * isPossible - is no. of coins fill all the cells up
 * @param n: no of coins
 * @param rows: no. of rows
 * @return: true or false
 */



bool isPossible(int n, long long rows){
    long long sum = (rows * (rows + 1)) / 2;
    return (n >= sum);
}

/**
 * arrangeCoins - count the number of coins that fill the rows
 * @param n: no of coins
 * @return: the number of rows that are full of coins
 */

int arrangeCoins(int n) {
    int start = 0, end = n, answer = 0;  // we make no. of rows == no. of coins (as a higher bound that will never reach)
    //find the last occurrence
    while (start <= end){
        long long mid = start + (end - start) / 2;
        if (isPossible(n, mid))
            start = mid + 1, answer = mid;
        else
            end = mid - 1;
    }
    return answer;
}