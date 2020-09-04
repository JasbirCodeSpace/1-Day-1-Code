#include <bits/stdc++.h>
using namespace std;

#define ll long long

int prec(char c)
{

    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
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

        string exp;
        cin >> exp;

        stack<char> stk;
        string postfix = "";

        for (int i = 0; i < N; i++)
        {
            char c = exp[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                postfix += c;
            }
            else
            {
                if (c == '(')
                {
                    stk.push('(');
                }
                else if (c == ')')
                {
                    while (!stk.empty() && stk.top() != '(')
                    {
                        char op = stk.top();
                        postfix += op;
                        stk.pop();
                    }
                    if (stk.top() == '(')
                    {
                        stk.pop();
                    }
                }
                else
                {

                    while (!stk.empty() && prec(c) <= prec(stk.top()))
                    {
                        char op = stk.top();
                        postfix += op;
                        stk.pop();
                    }
                    stk.push(c);
                }
            }
        }

        while (!stk.empty())
        {
            char c = stk.top();
            postfix += c;
            stk.pop();
        }

        cout << postfix << endl;
    }
}