#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

void arr_left_max(int arr[], int len){
    if(len == 0)
        return ;

    arr_left_max(arr,len-1);
    if(arr[len-1] > arr[len])
        arr[len] = arr[len-1];
}
