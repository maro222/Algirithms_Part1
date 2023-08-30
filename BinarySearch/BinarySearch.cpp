#include "BinarySearch.h"

/**
 * binary_search - search for target with complexity (log n)
 *
 * @param nums : the array of items
 * @param target : the specified item to search for
 * @return : index of target
 */

int binarySearch(vector<int>& nums, int target) {
    int start = 0, end = (int) nums.size() - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);   //better because of overflow than ==> //(start + end) / 2
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return (-1);
}

/*
 * complexity_time = O(lg n)
 * complexity_space = O(1)
 *
 */