#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

int pow(int n, int p){
    if(p == 0)
        return 1;
    return n * pow(n,--p);
}
