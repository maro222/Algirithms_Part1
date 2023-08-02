/**
 * intuition
 *   do the count sort once for positvie elements
 *     and another dor negative elements if there is
 *
 * another intuition
 *    we can shifting all the elements by the smallest specified range
 *    if range of elements [-50000 < n < 50000] we add to all elements 50000
 *    and on looping and assigning the values we add it again
 *
 * complexity_time: O(n+m) where n ==> the number of elements
 *                               m ==> the number of max or min elements
 *
 * complexity_space: O(n)
*/

#include "../Sorting.h"

vector<int> sortArray(vector<int>& nums) {
    int max = nums[0];
    int min = nums[0];
    // getting the maximum and minimum element
    for(int i = 1; i < nums.size(); i++)
    {
        if (max < nums[i])
            max = nums[i];

        if (min > nums[i] && nums[i] < 0)
            min = nums[i];
    }
    if (min < 0)
        min = -min;

    // making 2 vectors for positive and negative elements
    vector<int> count_pos(max + 1);
    vector<int> count_neg((min + 1));

    // making frequency array for each of them
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            count_neg[-nums[i]]++;
        else
            count_pos[nums[i]]++;
    }

    // we loop on each count(count[i]) and
    // assign the values it occurs to arr count[i] times (with incremental index)
    // once for negative elements
    int idx = 0;
    for(int i = min; i >= 0; i--)
        for(int j = 0; j < count_neg[i]; j++, idx++)
            nums[idx] = -i;

    // and once for positive elements
    for(int i = 0; i <= max; i++)
        for(int j = 0; j < count_pos[i]; j++, idx++)
            nums[idx] = i;

    return nums;
}


