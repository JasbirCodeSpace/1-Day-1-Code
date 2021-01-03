#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int A[N], B[M];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> B[i];
        }
        int result = 0;
        int sum_N = accumulate(A, A + N, 0), sum_M = accumulate(B, B + M, 0);
        while (sum_N < sum_M)
        {
            int i = distance(A, min_element(A, A + N));
            int j = distance(B, max_element(B, B + M));
            int temp = A[i];
            A[i] = B[j];
            B[j] = temp;
            result += 1;
            sum_N = accumulate(A, A + N, 0);
            sum_M = accumulate(B, B + M, 0);
        }
        if (sum_N == sum_M)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}