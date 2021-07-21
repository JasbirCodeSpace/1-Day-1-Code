#include<bits/stdc++.h>
using namespace std;

int minJumpsRec(int* arr, int n, int i);   // O(n^n)
int minJumpsDP(int* arr, int n);        // O(n^2)

/*
    Time: O(N^2)
    Space: O(N)
*/
int minJumpsDP2(int* arr, int n);
/*
    Time: O(N)
    Space: O(1)
*/
int minJumpsOpt(int* arr, int n);

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 6, 3, 2,
                  3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumpsOpt(arr, n);
    return 0;
}

int minJumpsRec(int* arr, int n, int i){

    if(i>=n-1)
        return 0;
    int minJump = INT_MAX;
    int maxSteps = arr[i];
    while(maxSteps>0){
        minJump = min(minJump, 1+minJumpsRec(arr, n, i+maxSteps));
        maxSteps--;
    }
    return minJump==INT_MAX?-1:minJump;
}

int minJumpsDP(int* arr, int n){

    int* minJump= new int[n];
    for(int i=0; i<n; i++)minJump[i] = INT_MAX;

    minJump[0] = 0;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < min(i+arr[i]+1, n); j++){
            if(minJump[i]!=INT_MAX)
            minJump[j] = min(minJump[j], 1+minJump[i]);
        }

    return (minJump[n-1] == INT_MAX)?-1:minJump[n-1];  
}

int minJumpsDP2(int* arr, int n){
    int dp[n];
    fill(dp, dp+n, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]+j >= i){
                if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1]==INT_MAX?-1:dp[n-1];
}

int minJumpsOpt(int* arr, int n){
    int jumps = 0;
    int current_far = 0, current_end = 0;

    for(int i=0; i<n; i++){
        current_far = max(current_far, arr[i]+i);
        if(current_end == i){
            jumps++;
            current_end = current_far;
        }
        if(current_end >= n-1){
            break;
        }
    }

    return current_end>=n-1?jumps:-1;
}