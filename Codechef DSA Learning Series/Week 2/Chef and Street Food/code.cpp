#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long

int main()
{

    FAST;
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        int max_profit = 0;
        int x = 0;
        while (N--)
        {
            int S, P, V;
            cin >> S >> P >> V;

            x = P / (S + 1);
            x = x * V;
            max_profit = max(x, max_profit);
        }
        cout << max_profit << endl;
    }
}