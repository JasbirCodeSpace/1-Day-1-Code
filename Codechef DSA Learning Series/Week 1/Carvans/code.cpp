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
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        int count = 0;
        if (N > 0)
            count = 1;
        int max_so_far = arr[0];

        for (int i = 1; i < N; i++)
        {
            if (arr[i] > max_so_far)
                continue;
            max_so_far = arr[i];
            count++;
        }

        cout << count << endl;
    }
    return 0;
}