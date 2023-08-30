#include "../BinarySearch.h"

/**
 *
 *
 * @param nums
 * @param threshold
 * @return
 */

int smallestDivisor(vector<int> nums, int threshold) {
    int start = 1, end = *max_element(nums.begin(),nums.end());  //----> O(n)
    int divisor = end;

    while (start <= end){
        int mid = start + (end - start) / 2;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += (int) ceil(nums[i] /(double) mid);

        if (sum > threshold)
            start = mid + 1;
        else
        {
            divisor = mid;
            end = mid - 1;
        }
    }
    return (divisor);
}