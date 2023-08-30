#include "../BinarySearch.h"



///**************************************Approach 1: Binary Search*****************************************\\\

//search for first bigger element than target
int Special_binarySearch(vector<vector<int>> starting, int target){
    int start = 0, end = starting.size() - 1;
    int mid, pos = -1;
    while (start <= end){
        mid  = start + (end - start) / 2;
        if (target > starting[mid][0])
            start = mid + 1;
        else
            end = mid - 1, pos = mid;
    }
    return (pos);
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> starting;
    for (int i = 0; i < intervals.size(); i++){
        starting.push_back({intervals[i][0], i});
    }

    sort(starting.begin(), starting.end());
    vector<int> ans;
    int idx;
    for(int i = 0; i < intervals.size(); i++){
        idx = Special_binarySearch(starting, intervals[i][1]);
        if (idx != -1)
            ans.push_back(starting[idx][1]);
        else
            ans.push_back(-1);
    }
    return (ans);
}



///********************************************Approach2 : Stl & map ******************************************\\\

vector<int> findRightInterval2(vector<vector<int>>& intervals) {
    vector<int> starting;
    map <int, int> mp;

    for (int i = 0; i < intervals.size(); i++){
        starting.push_back(intervals[i][0]);
        mp[intervals[i][0]] = i;
    }

    sort(starting.begin(), starting.end());
    vector<int> ans;
    int idx;
    for(int i = 0; i < intervals.size(); i++){
        idx = lower_bound(starting.begin(), starting.end(), intervals[i][1]) - starting.begin();
        if (idx != intervals.size())
            ans.push_back(mp[starting[idx]]);
        else
            ans.push_back(-1);
    }
    return (ans);
}