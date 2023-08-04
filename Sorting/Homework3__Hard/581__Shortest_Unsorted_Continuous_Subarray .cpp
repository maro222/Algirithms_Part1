#include "../Sorting.h"

/**
 * findUnsortedSubarray - this function return the length of continuous unsorted subarray
 *
 * @param nums : the array to process
 * @return : an integer ==> length of unsorted subarray
 */
int findUnsortedSubarray(vector<int>& nums) {
    int min_valid = 0, max_valid = 0;
    int size = nums.size();
    int max = nums[0], min = nums[0];

    // get the maximum and minimum element
    for(int i = 1; i < size; i++){
        if (max < nums[i])
            max = nums[i];
        if (min > nums[i])
            min = nums[i];
    }

    // shift all the elements to (+ve) value form [0 to 100000]
    for(int i = 0; i < size; i++)
        nums[i] -= min;

    // make 2 frequency vectors (one for min_valid and another for max_valid)
    vector<int> freq(max - min + 1);
    vector<int> freq2(max - min + 1);

    for(int i = 0; i < size; i++){
        freq[nums[i]]++;
        freq2[nums[i]]++;
    }

    // evaluating the min_valid (index of first unsorted element)
    for (int i = 0, j = 0; i < (max - min +1);)
    {
        if (freq2[i]--)
        {
            if (nums[j] != i)
            {
                min_valid = j;
                break;
            }
            ++j;
        }
        else
            i++;
    }

    // evaluating the max_valid (index of last unsorted element)
    for (int i = max - min, j = size - 1; i >= 0;)
    {
        if (freq[i]--)
        {
            if (nums[j] != i)
            {
                max_valid = j;
                break;
            }
            --j;
        }
        else
            --i;
    }

    // evaluating the length of subarray
    int sub_size = max_valid - min_valid + 1;
    if(sub_size == 1)
        sub_size = 0;

    return (sub_size);
}


/**
 * intuition
 *   we can use the spirit of count sort
 *   we make frequency array of size = (max + 1);
 *
 *   by looping on this freq we check the value of index:
 *        if(value of index == 0) ==> the index happens 0 times and we skip it
 *        else ==> we compare the index of it with original array as they should be equal in order to be sorted
 *                 if it does not it means that starting from this index it is unsorted (min_valid)
 *
 *         index     nums[j]
 *         0           1
 *         1           2
 *         2           2
 *         3           4
 *         4           3
 *         5           7
 *
 *         index      freq[i]
 *         0             0
 *         1             1
 *         2             2
 *         3             1
 *         4             1
 *         5             0
 *         6             0
 *         7             1
 *       as freq[0] == 0  we skip it (i++)
 *       as freq[1]  > 1  we compare it with the first element in nums[j]
 *
 *       if they are equal ==> sorted and we process to the next element in nums[j] (j++)
 *       note that in every iteration we decrement freq[i] to handle the repetitive elements of this index
 *
 *       once the unequal happens between nums[j] and freq[i] ==> it means that starting from this index it is unsorted
 *       and we break from the loop
 *
 *   by doing the same for max_valid (last index to be unsorted) we get the boundaries of unsorted subarray
 *
 *   note we handle the occurring of negative numbers by subtracting all elements form min element
 *
 *
 *   time_complexity = O(n)
 *   space_complexity = O(n)
 *
 *   More memory vector<int> freq(max-min+1), vector<int> freq2(max-min+1)
 *
 *
*/