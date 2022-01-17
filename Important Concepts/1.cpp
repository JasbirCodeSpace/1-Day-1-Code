// Concept: prefix sum
// Question: Given an array arr[] of size n.
// Given Q queries and in each query given L and R, print sum of array elements from index L to R.

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {3, 6, 2, 8, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int prefixSum[n] = {0};
    prefixSum[0] = arr[0];

    for(int i=1; i<n; i++){
        prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    int q;
    cin>>q;

    while(q--){
        int l, r;
        cin>>l>>r;

        if(l == 1)
            cout<<prefixSum[r-1]<<endl;
        else
            cout<<prefixSum[r-1] - prefixSum[l-2]<<endl;
    }

    return 0;
}

// Input : n = 6
//        a[ ] = {3, 6, 2, 8, 9, 2}
//        prefixSum[] = {3, 9, 11, 19, 28, 30}
//        q = 4
//        l = 2, r = 3.
//        l = 4, r = 6.
//        l = 1, r = 5.
//        l = 3, r = 6.
// Output :  8
//           19
//           28
//           21