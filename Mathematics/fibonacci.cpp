#include <bits/stdc++.h>
using namespace std;

void fib_series(int n);
long long int fib_recursive(int n);
long long int fib_dp(int n);

int main()
{

    int n;
    scanf("%d", &n);

    fib_series(n);
    long long int nth_elem = 0;

    // long long int nth_elem = fib_recursive(n);
    // printf("\nNth element of fibonacci series (Recurssion): %lld", nth_elem);

    nth_elem = fib_dp(n);
    printf("\nNth element of fibonacci series (DP): %lld", nth_elem);

    return 0;
}

void fib_series(int n)
{
    long long int first = 0, second = 1, temp = 0;

    for (int i = 0; i < n; i++)
    {
        temp = first;
        printf("%lld ", first);
        first = second;
        second = temp + first;
    }
}

long long int fib_recursive(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long int fib_dp(int n)
{
    long long int first = 0, second = 1, temp;
    for (int i = 1; i < n; i++)
    {
        temp = first;
        first = second;
        second = temp + first;
    }
    return first;
}
