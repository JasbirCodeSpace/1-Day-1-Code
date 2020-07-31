#include <bits/stdc++.h>
using namespace std;

long long int binomial_coeff(int n, int k);
int main()
{
    int n = 400, k = 19;
    printf("\nValue of C(%d, %d): %lld", n, k, binomial_coeff(n, k));
    return 0;
}

long long int binomial_coeff(int n, int k)
{
    long long int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(k, i); j > 0; j--)
        {
            C[j] = C[j] + C[j - 1];
        }
    }

    return C[k];
}