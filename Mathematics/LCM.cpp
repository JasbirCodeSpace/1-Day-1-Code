#include<bits/stdc++.h>

long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);

int main(){

    long long int num1, num2, result;

    scanf("%lld", &num1);
    scanf("%lld", &num2);

    result = lcm(num1, num2);

    printf("\nLCM of %lld and %lld: %lld \n", num1, num2, result);

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

long long int lcm(long long int a, long long int b){

    long long int hcf = gcd(a, b);
    long long int result = (a * b) / hcf;
    return result;
}