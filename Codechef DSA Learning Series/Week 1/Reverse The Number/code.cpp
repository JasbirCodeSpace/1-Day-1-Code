#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    char N[7];
    bool flag = false;

    while (T--)
    {
        scanf("%s", &N);
        for (int i = strlen(N) - 1; i >= 0; i--)
        {
            if (N[i] != '0')
                flag = true;
            if (flag)
                printf("%c", N[i]);
        }
        flag = false;
        printf("\n");
    }
    return 0;
}