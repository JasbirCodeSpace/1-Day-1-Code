#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    stack<char> p_stk, l_stk;
    string P, L;
    cin >> P;
    cin >> L;
    for (int i = 0; i < P.length(); i++)
    {
        char ch = P[i];
        if (ch == '#')
        {
            if (!p_stk.empty())
            {
                p_stk.pop();
            }
        }
        else
        {
            p_stk.push(ch);
        }
    }

    for (int i = 0; i < L.length(); i++)
    {
        char ch = L[i];
        if (ch == '#')
        {
            if (!l_stk.empty())
            {
                l_stk.pop();
            }
        }
        else
        {
            l_stk.push(ch);
        }
    }

    string pf = "", lf = "";
    while (!p_stk.empty())
    {
        pf += p_stk.top();
        p_stk.pop();
    }
    while (!l_stk.empty())
    {
        lf += l_stk.top();
        l_stk.pop();
    }

    if (pf == lf)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}