#include<iostream>
using namespace std;

int swapEvenOddBits(int n){                     // O(1)

    int evenBits = n & 0xAAAAAAAA;
    int oddBits = n & 0x55555555;
    return (evenBits>>1) | (oddBits<<1);
}
int main(){

    int n = 23;
    cout<<"n = "<<n<<endl;
    cout<<"After swapping even and odd bis, n = "<<swapEvenOddBits(n)<<endl;
    return 0;
}