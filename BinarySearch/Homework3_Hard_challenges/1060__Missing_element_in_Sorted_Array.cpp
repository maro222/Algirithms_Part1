#include "../BinarySearch.h"

/**
 * missingElement -
 * @param nums :
 * @param k :
 * @return :
 */                             /*Approach_1: linear search_O(n)*/
//int missingElement(vector<int> &nums, int k){
//    int start = nums[0];
//
//    for(int i = 0; ; start++)
//    {
//        if(start == nums[i])
//        {
//            i++;
//        }
//        else
//        {
//            if (k == 1)
//                return (start);
//            k--;
//        }
//    }
//}
//
//                                /*Approach_2: binary search_O(lgn)*/
/**
 * missing - to calculate the number missing elements
 * @param nums : array
 * @param idx : idx to calculate to it
 * @return : # of missing element
 */
 /*
  * (1) # of elements that should be between 2 elements = nums[idx] - nums[0] - 1
  * (2) # of elements that are between 2 elements = idx - 0 + 1
  *
  * (3) # of missing elements between those 2 elements = (2) - (1) = nums[idx] - nums[0] - idx
  */
int missing(vector<int> nums, int idx){  // O(1)
    return (nums[idx] - nums[0] - idx);
}
/**
 * Kth - find the Kth missing element
 * @param nums : vector
 * @param idx : idx of
 * @param k : Kth
 * @return
 */
 /*
  * this element find the Kth missing element from the
  * missing(last biggest element) < k
  *
  * that's why it finds Kth missing element if (k > missing(last biggest element))
  * as it will be the last biggest element that has missing elements < k
  *
  * (1) the range between the element that has missing(last biggest element) < k
  *     and the element that follow it (missing(after the last biggest element)) >= k
  *
  *     ==> will be the range in which the Kth element will be there
  *
  *  (2) # of moves(increments) that will be taken to reach to the Kth missing element=
  *                               Kth of missing element - number of missing element  = k - missing(nums, idx)
  *  (3) So the Kth missing element in the range will be =
  *                                start of range + number of moves = nums[idx] + k - missing(nums, idx)
  */
int Kth(vector<int> nums, int idx, int k){
    return (nums[idx] + k - missing(nums, idx));
}

/**
 *
 * @param nums
 * @param k
 * @return
 */
int missingElement_2(vector<int> &nums, int k){
    int n = nums.size() - 1;
    // kth missing number after last number?
    if (k > missing(nums, n))
        return (Kth(nums, n, k));

    int start = 0, end = n, lb = -1;
    // find the first idx where missing(idx) >= k
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (missing(nums, mid) >= k)
            end = mid - 1, lb = mid;
        else
            start = mid + 1;
    }
    // Use the previous idx (lower_bound - 1) to find the missing element
    return Kth(nums, lb - 1, k);
}