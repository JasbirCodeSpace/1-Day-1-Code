#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    iostream::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {

        int N;
        cin >> N;

        ll X;
        cin >> X;

        ll tokens = X;

        for (int i = 1; i < N; i++)
        {
            ll Y;
            cin >> Y;
            X = min(Y, X);
            tokens += X;
        }

        cout << tokens << endl;
    }
    return 0;
}