#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    FAST;
    short int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        vector<short int> firstHalf(26, 0);

        int length = S.length();
        for (int i = 0; i < length / 2; i++)
            firstHalf[S[i] - 'a']++;
        for (int j = (length + 1) / 2; j <= length - 1; j++)
            firstHalf[S[j] - 'a']--;

        bool flag = all_of(firstHalf.begin(), firstHalf.end(), [](int i) { return i == 0; });
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
