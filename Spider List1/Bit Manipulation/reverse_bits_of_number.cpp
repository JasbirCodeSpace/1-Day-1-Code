#include<iostream>
using namespace std;

int reverseBits(int n){                     // O(n)
    int totalBits = sizeof(n)*8;
    int result = 0;

    for(int i=0; i<totalBits; i++){
        if(n&(1<<i)){
            result |= (1<<(totalBits-i-1));
        }
    }
    return result;
}
int main(){

    int n = 2;
    cout<<reverseBits(n)<<'\n';
    return 0;
}