/**
 * what if range is too big but you know that
 * range between min_val and max_val <= 500
 *
 * this a another idea we apply count sort for it
 *
 * intuition
 *   we can subtract min_val from whole array to solve the
 *   very big range for array problem and in order to make the min_val is zero
 *   (-10, 20, 10) ==> (0, 30, 20)   || (10,20,30) ==> (0, 10, 20)
 *
 *   add it again on assigning it
 *
 *   complexity_time = O(n+m)
 *   complexity_space = O(n)
 *
 */

#include "../Sorting.h"

vector<int> sortArray(vector<int> &array) {
    int size = array.size();
    int mxVal = array[0], mnVal = array[0];

    for (int i = 1; i < size; ++i) {
        if (array[i] > mxVal)
            mxVal = array[i];
        if (array[i] < mnVal)
            mnVal = array[i];
    }
    int new_range = mxVal - mnVal;
    vector<int> count(new_range + 1);

    for (int i = 0; i < size; ++i)
        count[array[i] - mnVal] += 1;

    int idx = 0;
    for (int i = 0; i <= new_range; ++i) {
        for (int j = 0; j < count[i]; ++j, ++idx)
            array[idx] = i + mnVal;
    }
    return array;
}

