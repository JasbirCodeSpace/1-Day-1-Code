#include <bits/stdc++.h>
using namespace std;

void fib_series(int n);
long long int fib_recursive(int n);
long long int fib_dp(int n);
long long int fib_matrix(int n);
void power(long long int F[2][2], int n);
void matrix_multiply(long long int M1[2][2], long long int M2[2][2]);

int main()
{

    int n;
    scanf("%d", &n);

    fib_series(n);
    long long int nth_elem = 0;

    // long long int nth_elem = fib_recursive(n);
    // printf("\nNth element of fibonacci series (Recursion): %lld", nth_elem);

    nth_elem = fib_dp(n);
    printf("\nNth element of fibonacci series (DP): %lld", nth_elem);

    nth_elem = fib_matrix(n - 1);
    printf("\nNth element of fibonacci series (Matrix): %lld", nth_elem);

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

// Recursion Implementation
long long int fib_recursive(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Dynamic Programming Implementation
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

// Matrix Implementation

long long int fib_matrix(int n)
{

    long long int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

void power(long long int F[2][2], int n)
{
    if (n == 0 | n == 1)
        return;
    long long int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    matrix_multiply(F, F);
    if ((n & 1) == 1)
        matrix_multiply(F, M);
}

void matrix_multiply(long long int M1[2][2], long long int M2[2][2])
{
    long long int a, b, c, d;
    a = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
    b = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
    c = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
    d = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];

    M1[0][0] = a, M1[0][1] = b, M1[1][0] = c, M1[1][1] = d;
}