#include "../Sorting.h"

vector<int> countSort(const vector<int> &array) {
    // Find the largest element of the array
    int size = array.size();
    int mxVal = array[0];
    for (int i = 1; i < size; ++i)
        if (array[i] > mxVal)
            mxVal = array[i];

    // Compute Frequency
    vector<int> count(mxVal + 1);	// zeros
    for (int i = 0; i < size; ++i)
        count[array[i]] += 1;

    // Accumulate the counting
    for (int i = 1; i <= mxVal; ++i)
        count[i] += count[i - 1];

    // Find the index and put the number
    vector<int> output(size);
    for (int i = size - 1; i >= 0; --i) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }
    return output;
}

/**

1) More memory writes
	count[i] += count[i - 1];  and count[array[i]] -= 1;

2) Bad Locality of reference
	Optional reading: https://en.wikipedia.org/wiki/Locality_of_reference

3) More memory vector<int> output(size);
	However, this is used to create a stable order algorithm!

	But a must to process backward
		for (int i = size - 1; i >= 0; --i)

4) stable (most important)
====================================
Assume the input vector has content: 9, 5, 3, 9, 5, 9, 7
Computing the frequency:
	Freq 3 1
	Freq 5 2
	Freq 7 1
	Freq 9 3

Computing the accumulative sum array
	0 count[i] 0
	1 count[i] 0
	2 count[i] 0
	3 count[i] 1
	4 count[i] 1
	5 count[i] 3
	6 count[i] 3
	7 count[i] 4
	8 count[i] 4
	9 count[i] 7

But we only has interest int
	3 count[i] 1
	5 count[i] 3
	7 count[i] 4
	9 count[i] 7



The algorithm intuition
	If the frequency of is 3, and its accumulative sum is 7
		then we must have three 9s at locations: 6, 5, 4

		use this fact to get the right index for every number from its accumulation value



Now we build from the END of the array: for (int i = size - 1; i >= 0; --i)
                          0  1  2  3  4  5  6
	Recall array is:      9, 5, 3, 9, 5, 9, 7
	expected output is    3, 5, 5, 7, 9, 9, 9

	Put in idx 3 value 7 from idx 6
	Put in idx 6 value 9 from idx 5
	Put in idx 2 value 5 from idx 4
	Put in idx 5 value 9 from idx 3
	Put in idx 0 value 3 from idx 2
	Put in idx 1 value 5 from idx 1
	Put in idx 4 value 9 from idx 0

	Observe the three 9s were put relative to their input order
		9 from , then 3, then 0  [in reverse order]
		Hence stable algorithm
*/