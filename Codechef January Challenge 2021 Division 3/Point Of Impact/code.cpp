#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x, y;
        cin >> N >> K >> x >> y;

        if (x == y)
        {
            x = y = N;
            cout << x << " " << y << endl;
        }
        else
        {
            vector<pair<long long int, long long int>> points;

            if (x > y)
            {
                points.push_back(make_pair(N, N - x + y));
                points.push_back(make_pair(N - x + y, N));
                points.push_back(make_pair(0, x - y));
                points.push_back(make_pair(x - y, 0));
            }
            else
            {
                points.push_back(make_pair(N - y + x, N));
                points.push_back(make_pair(N, N - y + x));
                points.push_back(make_pair(y - x, 0));
                points.push_back(make_pair(0, y - x));
            }
            int idx = (K - 1) % 4;
            x = points[idx].first;
            y = points[idx].second;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}