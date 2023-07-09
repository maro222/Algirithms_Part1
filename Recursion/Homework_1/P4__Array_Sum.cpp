#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int arr_sum(int arr[], int len){
    if(len == 1)
        return arr[0];
    // base case is not necessarily
    return arr[len-1] + arr_sum(arr,len-1);
}
