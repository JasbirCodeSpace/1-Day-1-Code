#include<iostream>
using namespace std;

int countSetBits1(int n){           // O(logn)

    int c = 0;
    while(n){
        c += (n&1);
        n >>=1;
    }
    return c;
}

int countSetBits2(int n){           // O(logn)
    
    int c = 0;
    while(n){
        n = n & (n-1);
        c++;
    }
    return c;
}
int main(){

    int n = 9;
    cout<<countSetBits1(n)<<'\n';
    cout<<countSetBits2(n)<<'\n';
    return 0;
}