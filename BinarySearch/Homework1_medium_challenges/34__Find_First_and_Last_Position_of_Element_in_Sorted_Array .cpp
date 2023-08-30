#include "../BinarySearch.h"

/**
 * searchRange - search for range of first nd last occurrence of target
 *
 * @param nums:
 * @param target:
 * @return: first nd last occurrence of target
 */


/*
 * complexity-time = O(lg n)
 * space_complexity = O(1)
 */

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int second = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    if (first == nums.size() || nums[first] != target)
        return {-1, -1};

    ans.emplace_back(first);
    ans.emplace_back(second - 1);

    return ans;
}


/***************************************** Approach 2 First Code *****************************************/


/*

    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(1), since we stored only some constant number of elements, the space complexity is
    constant.

    Solved using Binary Search.

*/




class Solution {
private:
    //** return the first occurrence of target if it is repeated  **//
    int special_binarySearch(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int startingPosition = special_binarySearch(nums, low, high, target);
        int endingPosition = special_binarySearch(nums, low, high, target + 1) - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};