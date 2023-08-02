/**
 * this Algorithm has spirit of Count sort
 *
 * we can evaluate each 2 letters by certain value
 * and sort the vector by this value
 *
 * the value is counted like flatting 2D array to 1D array  (row * cols + j)
 * like if you have 6 , 7 ==> it will be 6 * 10(range) + 7 = 67
 *
 * we count sort according to this value by same way of version 1
 *
 * complexity_time = O(n+m)
 * complexity_space = O(n)
 * stable
 *
 */

#include "../Sorting.h"
const int chars_size = 26;

int countValue(const string &str){
    int f = str[0] - 'a';
    int s = str[1] - 'a';

    return f * chars_size + s;
}

void countSortForStrings_V2(vector<string> &array){
    int size = array.size();
    const int range = chars_size * chars_size;
    vector<vector<string>> letters_to_string(range);

    for(int i = 0; i < size; i++)
        letters_to_string[countValue(array[i])].push_back(array[i]);

    int idx = 0;
    for(int val = 0; val < range; val++)
        for(int str_idx = 0; str_idx < letters_to_string[val].size(); str_idx++, idx++)
            array[idx] = letters_to_string[val][str_idx];
}
