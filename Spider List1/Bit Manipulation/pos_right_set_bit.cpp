#include<iostream>
#include<math.h>
using namespace std;

int posRightMostBit1(int n){            // O(logn)
    return log2(n & (-n)) + 1;
}

int posRightMostBit2(int n){            // O(logn)

    if(n==0)return 0;

    int mask = 1;
    int pos = 1;
    while (!(n & mask))
    {
        mask <<= 1;
        pos++;
    }
    return pos;
}
int main(){

    int n = 12;
    cout<<"n = "<<n<<endl;
    cout<<"Right most set bit position: "<<posRightMostBit1(n)<<endl;
    cout<<"Right most set bit position: "<<posRightMostBit2(n)<<endl;
    return 0;
}