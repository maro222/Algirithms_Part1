#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

bool is_palindrome(int arr[],int len,int idx){
    if(idx == len/2)
        return true;
    if(arr[len - idx - 1] != arr[idx])
        return false;
    return is_palindrome(arr, len, ++idx);
}
