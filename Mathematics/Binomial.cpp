#include <bits/stdc++.h>
using namespace std;

long long int binomial_recursive(int n, int k);
long long int binomial_dp(int n, int k);
long long int binomial_pascal(int n, int k);

int main()
{
    int n, k;
    long long int binomial_coeff;

    printf("\nEnter n: ");
    scanf("%d", &n);

    printf("\nEnter k: ");
    scanf("%d", &k);

    binomial_coeff = binomial_recursive(n, k);
    printf("\nValue of C(%d, %d) (using recursion): %lld", n, k, binomial_coeff);

    binomial_coeff = binomial_dp(n, k);
    printf("\nValue of C(%d, %d) (using DP): %lld", n, k, binomial_coeff);

    binomial_coeff = binomial_pascal(n, k);
    printf("\nValue of C(%d, %d) (using Pascal Triangle): %lld", n, k, binomial_coeff);
    return 0;
}

// Time Complexity: O(n*n)
long long int binomial_recursive(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return binomial_recursive(n - 1, k - 1) + binomial_recursive(n - 1, k);
    }
}

// Time Complexity: O(n*k) and Auxilliary Space: O(n*k)
long long int binomial_dp(int n, int k)
{
    long long int C[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            // Best Cases
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            // Calculated values using previously stored values
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

// Time Complexity: O(n*k) and Auxilliary Space: O(k)
long long int binomial_pascal(int n, int k)
{

    long long int C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int j = min(i, k);
        while (j > 0)
        {
            C[j] = C[j] + C[j - 1];
            j--;
        }
    }

    return C[k];
}