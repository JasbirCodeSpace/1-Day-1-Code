#include<iostream>
using namespace std;

int add(int x, int y){

    int carry = 0;
    while(y){

        carry = x & y;
        x = x ^ y;
        y = carry<<1;
    }
    return x;
}

int sub(int x, int y){

    int borrow = 0;
    while(y){
        borrow = (~x)&y;
        x = x ^ y;
        y = borrow<<1;
    }
    return x;
}
int main(){

    int x = 10, y = 5;
    cout<<"x = "<<x<<", y = "<<y<<endl;
    cout<<"x + y = "<<add(x, y)<<endl;
    cout<<"x - y = "<<sub(x, y)<<endl;
    return 0;
}