#include "../Sorting.h"

/**
 * reductionOperations - a function that counts the number of operations to
 *                       make all elements equal
 *
 * @param nums : list of elements to process
 * @return : number of operations
 */

int reductionOperations(vector<int>& nums) {
    int acc = 1,sum = 0;
    sort(nums.begin(), nums.end());   //NlogN

    for(int i = nums.size() - 1; i >= 0; i--) {   //N
        if (nums[i] > nums[i - 1])
            sum += acc;
        acc++;
    }
    return (sum);
}

/*
 * intuition
 *
 *    Assume that nums has size = 5  == [1,2,3,4,5]
 *    it means that 5 is accumulated to be reduced to 4
 *    after that 4 (previously 5) , 4 are accumulated to be reduced to 3
 *    after that 3 (previously 5) , 3 (previously 4) , 3 are accumulated to 2
 *    and so on ... until all the accumulated elements are equal (there is no more next largest element)
 *
 *    first we sort nums
 *    by looping on sorted vector reversely we compare elements
 *    if(nums[i] == nums[i-1]) ==> then those elements are accumulated
 *                       until they found next largest elements(strictly the smallest element)
 *                       and we count those operations only then
 *                       if it is not found ==> this means that those accumulated elements are already the smallest
 *                                             and there is no need to count their operations
 *
 *    Time_Complexity: O(Nlog(N))
 *    Space_Complexity : O(1)
 */