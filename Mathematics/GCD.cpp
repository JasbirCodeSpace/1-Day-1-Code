#include<bits/stdc++.h>

long long int gcd(long long int a, long long int b);

int main(){
    long long int num1, num2;
    scanf("%lld", &num1);
    scanf("%lld", &num2);

    long long int result = gcd(num1, num2);
    printf("GCD of %lld and %lld is %lld", num1, num2, result);

    return 0;
}

long long int gcd(long long int a, long long int b){

    long long int r = 0;
    while(b){

        r = a % b;
        a = b;
        b = r;
    }
    return a;
}