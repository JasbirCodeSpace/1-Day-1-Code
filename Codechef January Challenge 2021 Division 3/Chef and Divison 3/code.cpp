#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, K, D;
        cin >> N >> K >> D;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int sum = 0;
        sum = accumulate(A, A + N, sum);
        int answer = sum / K;
        if (answer > D)
            cout << D << endl;
        else
            cout << answer << endl;
    }

    return 0;
}