#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"

using namespace std;

int length(int n,int cnt ){

    if(n==1){
        return cnt;
    }
    if(n % 2 == 0)
        length(n/2, ++cnt);
    else
        length(3*n+1, ++cnt);

    return 0;
}
