using namespace std;

#ifndef RECURSION_RECURSION_H
#define RECURSION_RECURSION_H

int length(int n,int cnt = 1);
int pow(int n, int p = 2);
int arr_max(int arr[], int len);
int arr_sum(int arr[], int len);
double arr_average(int arr[], int len);
void arr_increment(int arr[], int len);
void arr_accumulate(int arr[], int len);
void arr_left_max(int arr[], int len);

void arr_right_max(int arr[], int len,int start_pos = 0);
int arr_suffix_sum(int arr[],int len,int n);
int arr_prefix_sum(int arr[],int len,int n);
bool is_palindrome(int arr[],int len,int idx = 0);
bool is_prefix(string main, string prefix, int start_pos = 0);
int count_primes(int start, int end);
int path_sum(int grid[100][100], int cur_row = 0, int cur_col = 0, int rows = 0, int cols = 0);
int fibonacci (int n);

#endif //RECURSION_RECURSION_H
