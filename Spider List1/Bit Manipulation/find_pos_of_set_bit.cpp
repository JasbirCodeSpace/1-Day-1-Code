#include<iostream>
using namespace std;

bool isPowerOfTwo(int n){
    return n && (!(n & (n-1)));
}

int posOfSetBit(int n){                 // O(logn)

    if(!isPowerOfTwo(n))
        return -1;
    int pos = 1;
    int mask = 1;

    while(!(n & mask)){
        mask <<= 1;
        pos++;
    }

    return pos;
}
int main(){    
    
    int n = 16;
    int pos = posOfSetBit(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    n = 12;
    pos = posOfSetBit(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    n = 128;
    pos = posOfSetBit(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    return 0;
}