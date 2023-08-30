#include "../BinarySearch.h"

/**
 * triangleNumber - find the number of valid triplets
 *
 * @param nums: the vector of side lenghts
 * @return: number of valid triplets
 */


///********************************************first Approach: Stl**************************************\\\

int triangleNumber(vector<int>& nums) {     // O(n^2 log n)
    int cnt = 0, fst_idx;
    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            int k = j + 1;
            fst_idx = nums.size();
            auto iter = lower_bound(nums.begin()+k, nums.end(), nums[i] + nums[j]);
            if (iter != nums.end()) {
                fst_idx = iter - nums.begin();
            }
            cnt += fst_idx - j - 1;
        }
    }
    return (cnt);
}



///*********************************************second Approach : binary search***********************\\\


int special_binarySearch(vector<int> &nums, int target, int start){ // O(log n)
    int end = (int) nums.size() - 1;
    int pos  = nums.size();
    while (start <= end){
        int mid = start + (end - start) / 2;
        if(target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1, pos = mid;
    }
    return (pos);
}


int triangleNumber2(vector<int>& nums) {     // O(n^2 log n)
    int cnt = 0, fst_idx;
    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            int k = j + 1;
            fst_idx = special_binarySearch(nums, nums[i] + nums[j], k);
            cnt += fst_idx - j - 1;
        }
    }
    return (cnt);
}


///********************************************third Approach **************************************\\\

int triangleNumber3(vector<int>& nums) {     // O(n^2 )
    int cnt = 0;
    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {  // n steps
        for (int j = i + 1; j < nums.size() - 1; j++) {  // n steps in each i loop
            int k = j + 1;
            while (k < nums.size() && k < nums[i] + nums[j])   // n - 2 steps in all j loops ==> fake loop
                k++;
            cnt += k - j - 1;
        }
    }
    return (cnt);
}