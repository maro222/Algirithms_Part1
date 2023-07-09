#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int arr_prefix_sum(int arr[],int len,int n){
    if(n == 1)
        return arr[n-1];

    return arr[n-1] + arr_prefix_sum(arr,len,--n);
}
