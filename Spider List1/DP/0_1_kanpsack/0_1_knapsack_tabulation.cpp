#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N*W)
    Space Complexity: O(N*W)
*/
int knapsack(int W, int* wt, int* val, int n);
int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n);
    return 0;
}

int knapsack(int W, int* wt, int* val, int n){

    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++)
        dp[i] = new int[W+1];
    
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
        }
        
    }
    return dp[n][W];
}