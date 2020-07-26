#include<bits/stdc++.h>

long long int  pow_recursive(long long int a, long long int b);
long long int  pow_iterative(long long int a, long long int b);

int main(){
    long long int base = 0;
    long long int exp = 0;
    scanf("%lld", &base);
    scanf("%lld", &exp);
    printf("Base: %lld \n", base);
    printf("Exponent: %lld \n", exp);
    
    clock_t start, end;
    double time_taken;

    start = clock();
    long long int result1 = pow_recursive(base, exp);
    end = clock();
    time_taken = double(end - start);
    printf("Result1 : %lld, Execution time: %f \n", result1, time_taken/CLOCKS_PER_SEC);

    start = clock();
    long long int result2 = pow_iterative(base, exp);
    end = clock();
    time_taken = double(end - start);
    printf("Result2 : %lld, Execution time: %f \n", result2, time_taken/CLOCKS_PER_SEC);
    return 0;

}

long long int pow_recursive(long long int a, long long int n){
    if(n==0) return 1;
    if(n==1) return a;
    long long int t = pow_recursive(a, n/2);
    return t * t * pow_recursive(a, (n & 1));
}

long long int pow_iterative(long long int a, long long int n){

    long long int t = 1;
    while(n){
        if((n & 1)== 1)
            t *= a;
        a *= a;
        n = n/2;
    }

    return t;
}