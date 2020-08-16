#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int result = 0;

        for (int i = 5; (N / i) >= 1; i *= 5)
        {
            result += (N / i);
        }

        cout << result << endl;
    }

    return 0;
}