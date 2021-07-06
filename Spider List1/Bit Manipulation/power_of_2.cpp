#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo1(int n);         // O(Log2 N)
bool isPowerOfTwo2(int n);        // O(Log2 N)
bool isPowerOfTwo3(int n);       // O(1)
bool isPowerOfTwo4(int n);      // O(logN)
int main(){
    
    cout<<isPowerOfTwo2(13)<<'\n';
    cout<<isPowerOfTwo2(64)<<'\n';
    return 0;
}

bool isPowerOfTwo1(int n){
    if(n==0)return false;

    return floor(log2(n)) == ceil(log2(n));
}

bool isPowerOfTwo2(int n){
    if(n == 0)return false;
    while(n!=1){
        if(n&1)return false;
        n >>= 1;
    }
    return true;
}

bool isPowerOfTwo3(int n){

    return n && !(n & (n-1));
}

bool isPowerOfTwo4(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count==1;
}