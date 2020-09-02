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
        int shots = 0;

        string S = "";
        cin >> S;

        int A = 0, B = 0;
        int A_shots_remain = N, B_shots_remain = N;

        for (int i = 0; i < S.length(); i++)
        {
            bool even = (i & 1) == 0 ? true : false;

            if (even)
            {
                if (S[i] == '1')
                {
                    A++;
                }
                A_shots_remain--;
            }
            else
            {
                if (S[i] == '1')
                {
                    B++;
                }
                B_shots_remain--;
            }
            if (A > (B + B_shots_remain) || B > (A + A_shots_remain))
            {
                shots = i + 1;
                break;
            }
        }
        if (shots == 0)
            shots = 2 * N;
        cout << shots << endl;
    }

    return 0;
}