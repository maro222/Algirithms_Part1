#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int target);

//Homework1
vector<int> searchRange(vector<int>& nums, int target);
vector<int> findRightInterval(vector<vector<int>>& intervals);   //Approach 1
vector<int> findRightInterval2(vector<vector<int>>& intervals);  //Approach 2
int triangleNumber(vector<int>& nums);


//Homework2
int smallestDivisor(vector<int> nums, int threshold);
int minDays(vector<int>& bloomDay, int m, int k);
int findRadius(vector<int> houses, vector<int> heaters);

Homework3
int missingElement(vector<int> &nums, int k);
int missingElement_2(vector<int> &nums, int k);

#endif //BINARYSEARCH_BINARYSEARCH_H
