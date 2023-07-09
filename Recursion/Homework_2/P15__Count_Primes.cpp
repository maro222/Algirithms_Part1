#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

bool is_prime(int val,int test = 2){
    if(test >= val/2)         //if val is not divisible by numbers
        return true;          // that is less than or equal half it then its prime

    if(val == 2)              // handling for the only even exception
        return true;

    if(val <= 1)              // handling for negative numbers
        return false;         // we can add handling for even numbers --> if(val <= 1 || val % 2 == 0)
    // as they are not prime except 2 but ist was necessary

    if(val % test == 0)       // if it is divisible then it is not prime
        return false;

    return is_prime(val, test+1);     // increment of test to use recursion as loops
}

int count_primes(int start, int end){
    if(start > end)       // base case
        return 0;

    int cnt = 0;          // counter for primes

    if (is_prime(start))   // if start is prime
        cnt = 1 + count_primes(start+1, end);       //then add 1 to cnt and check the next number
    else
        cnt = count_primes(start+1, end);           //else just check the next number

    return cnt;
}
