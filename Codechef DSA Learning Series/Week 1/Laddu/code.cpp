#include <bits/stdc++.h>
using namespace std;

// Fast i/o
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long

int main()
{

    FAST;
    ll T;
    cin >> T;

    while (T--)
    {

        ll A;
        cin >> A;

        string O;
        cin >> O;

        ll laddus = 0;
        ll months = 0;

        while (A--)
        {
            string a;
            cin >> a;
            if (a == "CONTEST_WON")
            {
                ll rank;
                cin >> rank;
                laddus += 300;
                if (rank <= 20)
                    laddus += 20 - rank;
            }
            else if (a == "TOP_CONTRIBUTOR")
            {
                laddus += 300;
            }
            else if (a == "BUG_FOUND")
            {
                ll severity;
                cin >> severity;
                laddus += severity;
            }
            else if (a == "CONTEST_HOSTED")
            {
                laddus += 50;
            }
        }

        if (O == "INDIAN")
            months = laddus / 200;
        else if (O == "NON_INDIAN")
            months = laddus / 400;

        cout << months << endl;
    }

    return 0;
}