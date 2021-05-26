#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N*W)
    Space Complexity: O(N*W)
*/
int knapsackRec(int W, int* wt, int* val, int i, int** dp);
int knapsack(int W, int* wt, int* val, int n);
int main(int argc, char const *argv[])
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n);
    return 0;
}

int knapsack(int W, int* wt, int* val, int n){

    int **dp = new int*[n];

    for (int i = 0; i < n; i++)
        dp[i] = new int[W+1];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<W+1; j++)
            dp[i][j] = -1;
    
    return knapsackRec(W, wt, val, n-1, dp);
    
}

int knapsackRec(int W, int* wt, int* val, int i, int** dp){

    if(i<0)
        return 0;
    if(dp[i][W]!=-1)
        return dp[i][W];
    if(wt[i]>W){
        dp[i][W] = knapsackRec(W, wt, val, i-1, dp);
        return dp[i][W];
    }else{
        dp[i][W] = max(knapsackRec(W, wt, val, i-1, dp),
                        val[i]+knapsackRec(W-wt[i], wt, val, i-1, dp));
        return dp[i][W];
    }
}