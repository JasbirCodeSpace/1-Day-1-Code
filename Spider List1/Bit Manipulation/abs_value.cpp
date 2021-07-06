#include<iostream>
using namespace std;

int abs1(int n){                                // O(1)
    int mask = n >> (sizeof(int)*8 - 1);
    return (n + mask) ^ mask;
}

int abs2(int n){                                // O(1)
    int mask = n >> (sizeof(int)*8-1);
    return (n ^ mask) - mask;
}
int main(){

    int n = -6;
    cout << "Absoute value of " << n << " is " << abs1(n)<<'\n';
    cout << "Absoute value of " << n << " is " << abs2(n)<<'\n';
    return 0;
}