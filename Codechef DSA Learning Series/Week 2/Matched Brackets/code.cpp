#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    iostream::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string inp(N, '0');

    stack<char> stk;
    pair<int, int> depth = {0, 0};
    pair<int, int> symbol = {0, 0};

    int start = 0, count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> inp[i];
    }

    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] == '1')
        {

            if (stk.empty())
            {
                start = i;
                count = 0;
            }
            stk.push('1');
            if (stk.size() > depth.second)
            {
                depth.first = i + 1;
                depth.second = stk.size();
            }
        }
        else
        {
            stk.pop();
            if (stk.empty())
            {
                if (count > symbol.second)
                {
                    symbol.first = start + 1;
                    symbol.second = count + 1;
                    count = 0;
                }
            }
        }
        count++;
    }

    cout << depth.second << " " << depth.first << " " << symbol.second << " " << symbol.first << endl;

    return 0;
}