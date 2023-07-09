#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

void arr_right_max(int arr[], int len,int start_pos){
    if(len == 1 || len == start_pos)
        return ;
    if(arr[len-2] < arr[len-1])
        arr[len-2] = arr[len-1];
    arr_right_max(arr,len-1,start_pos);
}
