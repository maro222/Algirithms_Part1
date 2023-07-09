#include <bits/stdc++.h>
#include <iostream>
#include "../Recursion.h"
using namespace std;
int max(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3)
        return num1 ;
    else if(num2 > num1 && num2 > num3)
        return num2;
    else
        return num3;
}

int path_sum(int grid[100][100], int cur_row , int cur_col , int rows , int cols ){
    if(cur_col >= cols-1 && cur_row >= rows-1)   //base case
        return grid[cur_row][cur_col];

    int num;
    if(cur_col >= cols-1)
        num = grid[cur_row + 1][cur_col];
    else if(cur_row >= rows-1)
        num = grid[cur_row][cur_col + 1];
    else
        num = max(grid[cur_row + 1][cur_col], grid[cur_row][cur_col + 1], grid[cur_row + 1][cur_col + 1]);

    if(num == grid[cur_row + 1][cur_col])
        return (grid[cur_row][cur_col] + path_sum(grid,cur_row + 1, cur_col, rows, cols));
    else if(num == grid[cur_row][cur_col + 1])
        return (grid[cur_row][cur_col] + path_sum(grid,cur_row, cur_col + 1, rows, cols));
    else
        return (grid[cur_row][cur_col] + path_sum(grid,cur_row + 1, cur_col + 1, rows, cols));
}