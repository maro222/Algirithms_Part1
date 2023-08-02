/**
 * this Algorithm has the spirit of count sort for 1st letter only
 * for each letter ==> holds a list of strings
 * after building it :
 *    we iterate on each letter and print its list of string
 *
 * complexity_time = O(n+m)
 * complexity_space = O(n)
 * stable Algorithm
 *
 */

#include "../Sorting.h"

void CountSortForStrings(vector<string> &array){
    int size = array.size();
    const int chars = 26;
    vector<vector<string>> letters_to_string(chars);

    for(int i = 0; i < size; i++)
        letters_to_string[array[i][0] - 'a'].push_back(array[i]);

    int idx = 0;
    for(int letters = 0; letters < chars; letters++)
        for(int str_idx = 0; str_idx < letters_to_string[letters].size(); str_idx++, idx++)
            array[idx] = letters_to_string[letters][str_idx];
}