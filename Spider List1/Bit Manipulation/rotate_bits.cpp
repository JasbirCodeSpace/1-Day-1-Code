#include<iostream>
using namespace std;

#define INT_BITS sizeof(int)*8

int leftRotateBits(int n, int d){                   // O(1)

    return (n << d)|(n >> (INT_BITS - d));
}

int rightRotateBits(int n, int d){                  // O(1)

    return (n >> d) | (n << (INT_BITS - d));
}

int main(){

    int n = 16;
    int d = 2;
    cout << "Left Rotation of " << n <<" by " << d << " is "<<leftRotateBits(n, d)<<'\n';
    cout << "Right Rotation of " << n <<" by " << d << " is "<<rightRotateBits(n, d)<<'\n';
    return 0;
}