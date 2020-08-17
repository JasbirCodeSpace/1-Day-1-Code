#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{

    FAST;
    int T;
    cin >> T;
    while (T--)
    {

        int G;
        cin >> G;

        while (G--)
        {
            int I;
            cin >> I;
            long N;
            cin >> N;
            int Q;
            cin >> Q;

            long result = 0;
            if ((N & 1) == 0)
            {
                result = N / 2;
            }
            else
            {
                if (I == Q)
                    result = (N - 1) / 2;
                else
                    result = (N + 1) / 2;
            }
            cout << result << endl;
        }
    }

    return 0;
}