#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long

int main()
{
    int N;
    cin >> N;

    ll arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    ll revenue = -1;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        revenue = max(revenue, (N - i) * arr[i]);
    }

    cout << revenue << endl;

    return 0;
}