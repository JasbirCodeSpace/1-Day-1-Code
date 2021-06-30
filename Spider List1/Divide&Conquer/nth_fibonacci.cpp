#include<iostream>
using namespace std;

int fibRecursive(int n){                // O(2^n)
    if(n<=1)
        return n;

    return fibRecursive(n-1)+fibRecursive(n-2);
}

int fibDP(int n){                   // O(n)
    int fib[n+1];

    fib[0]=0;fib[1]=1;

    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }

    return fib[n];
}

int fibSpaceOptimized(int n){               // O(n)

    int a, b, c;
    a = 0;
    b = 1;
    if(n==0)return a;
    if(n==1)return b;
    for(int i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int fibMatrix(int n);                           // O(logn)
void power(int F[2][2], int n);
void multiply(int F[2][2], int M[2][2]);

int main(int argc, char const *argv[])
{
    int n = 9;
    cout<<fibMatrix(n)<<endl;

    return 0;
}

int fibMatrix(int n){
    if(n==0)
        return 0;
    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n-1);
    return F[0][0];
}

void power(int F[2][2], int n){
    if(n<=1)
        return;
    
    power(F, n/2);
    multiply(F, F);
    if(n&1){
        int M[2][2] = {{1, 1}, {1, 0}};
        multiply(F, M);
    }
}

void multiply(int F[2][2], int M[2][2]){

    int a = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int b = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int c = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int d = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}