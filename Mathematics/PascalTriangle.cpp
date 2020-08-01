#include <bits/stdc++.h>
using namespace std;

void pascal_triangle(int n);

int main()
{
    int n;
    printf("\nEnter value for n: ");
    scanf("%d", &n);

    pascal_triangle(n);

    return 0;
}

// Time Complexity: O(n^2) and Auxilliary Space: O(1)
void pascal_triangle(int n)
{

    long long int C = 0;
    for (int line = 1; line <= n; line++)
    {
        C = 1;
        for (int i = 1; i <= line; i++)
        {
            printf("%lld ", C);
            C = C * (line - i) / i;
        }
        printf("\n");
    }

    return;
}