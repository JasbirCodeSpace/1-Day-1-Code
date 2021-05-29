#include<bits/stdc++.h>
using namespace std;

int minJumpsRec(int* arr, int n, int i);   // O(n^n)
int minJumpsDP(int* arr, int n);        // O(n^2)
int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 6, 3, 2,
                  3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumpsDP(arr, n);
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