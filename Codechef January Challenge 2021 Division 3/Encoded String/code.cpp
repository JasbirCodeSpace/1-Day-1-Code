#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        char S[N];
        cin >> S;
        int size = N / 4;
        string result = "";
        for (int i = 0; i < size; i++)
        {
            int idx = i * 4;
            char ch = 97 + ((int)S[idx + 0] - 48) * 8 + ((int)S[idx + 1] - 48) * 4 + ((int)S[idx + 2] - 48) * 2 + ((int)S[idx + 3] - 48) * 1;
            result += ch;
        }
        cout << result << endl;
    }

    return 0;
}