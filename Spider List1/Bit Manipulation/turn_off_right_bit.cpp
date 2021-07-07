#include<iostream>
using namespace std;


int turnoffRightBit(int n){             // O(1)
    return n&(n-1);
}

int main(){

    int n = 7;
    cout<<"n = "<<n<<endl;
    cout<<"after right most set bit off, n =  "<<turnoffRightBit(n)<<endl;

    n = 12;
    cout<<"n = "<<n<<endl;
    cout<<"after right most set bit off, n =  "<<turnoffRightBit(n)<<endl;
    return 0;
}