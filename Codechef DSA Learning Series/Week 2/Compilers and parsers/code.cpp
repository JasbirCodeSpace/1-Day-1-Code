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

        stack<char> exp_stack;
        string exp_string;
        cin >> exp_string;

        int answer = 0;
        for (int i = 0; i < exp_string.length(); i++)
        {
            if (exp_string[i] == '<')
            {
                exp_stack.push('<');
            }
            else
            {
                if (exp_stack.empty())
                {
                    break;
                }
                else
                {
                    exp_stack.pop();
                }
            }
            if (exp_stack.empty())
            {
                answer = i + 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}