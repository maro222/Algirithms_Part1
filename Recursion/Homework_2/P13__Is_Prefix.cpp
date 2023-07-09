#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;

bool is_prefix(string main, string prefix, int start_pos){
    if(prefix[start_pos] == '\0')
        return true;
    if(prefix[start_pos] != main[start_pos])
        return false;
    return is_prefix(main, prefix, ++start_pos);
}
