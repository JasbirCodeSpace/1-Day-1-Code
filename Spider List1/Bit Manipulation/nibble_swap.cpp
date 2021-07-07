#include<iostream>
using namespace std;

int nibbleSwap(int n){                      // O(1)
    unsigned int first = n & 0x0F;
    unsigned int second = n & 0xF0;
    return (first<<4 | second>>4);
}
int main(){

    int n = 100;
    cout<<"n = "<<n<<endl;
    cout<<"After nibble swap, n = "<<nibbleSwap(n)<<endl;
    return 0;
}