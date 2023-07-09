#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int fibonacci (int n){
    if(n == 0 || n == 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}
