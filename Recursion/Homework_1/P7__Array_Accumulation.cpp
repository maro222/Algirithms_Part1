#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

void arr_accumulate(int arr[], int len){
    if(len == 1)
        return ;
    arr_accumulate(arr,len-1);
    arr[len-1] = arr[len-1] + arr[len-2];
}
