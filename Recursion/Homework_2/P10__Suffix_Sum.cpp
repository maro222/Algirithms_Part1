#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int arr_suffix_sum(int arr[],int len,int n){
    if(n == len)
        return arr[len - 1];

    return arr[n-1] + arr_suffix_sum(arr,len,++n);
}
