#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int arr_max(int arr[], int len){
    if(len == 1){
        return arr[0];
    }

    int maxSubtract = arr_max(arr,len-1);
    return max(arr[len-1],maxSubtract);
}
