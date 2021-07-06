#include<iostream>
using namespace std;

int countFlipBits(int a, int b){            // O(logn)
    int res = a ^ b;
    int c = 0;
    while(res){
        c += (res&1);
        res >>= 1;
    }
    return c;
}
int main(){

    int a = 4, b = 3;
    cout<<countFlipBits(a, b)<<'\n';
    return 0;
}