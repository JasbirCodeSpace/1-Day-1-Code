#include<bits/stdc++.h>
using namespace std;

int knapSack_recursion(int W, int* wt, int* val, int n); // O(2^n)
int main(){

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack_recursion(W, wt, val, n);
}

int knapSack_recursion(int W, int* wt, int* val, int n){
    if(W == 0 || n == 0)   // base case
        return 0;
    if(wt[n-1]>W)   // skip case
        return knapSack_recursion(W, wt, val, n-1);
    else{       // return max of result of including or excluding the current weight
        return max(val[n-1] + knapSack_recursion(W-wt[n-1], wt, val, n-1),
                    knapSack_recursion(W, wt, val, n-1));
    }
}