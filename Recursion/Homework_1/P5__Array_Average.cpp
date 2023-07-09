#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

double arr_average(int arr[], int len){
    if(len == 1)
        return arr[0];

    double sub_result = arr_average(arr,len-1); //average of first n-1 numbers (by division of n-1)
    sub_result *= (len - 1);                        //sum of first n-1 number (by multiplication of n-1)
    return ((sub_result + arr[len-1]) / len);
}

