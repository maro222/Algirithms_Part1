#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

void arr_increment(int arr[], int len){
    if(len == 0)
        return ;
    arr[len-1] = arr[len-1] + (len-1);
    arr_increment(arr,len-1);
}
