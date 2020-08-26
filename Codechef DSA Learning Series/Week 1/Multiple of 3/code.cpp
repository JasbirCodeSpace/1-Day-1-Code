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

    for (int i = 1; i <= T; i++)
    {
        ll K, d0, d1;
        cin >> K >> d0 >> d1;

        ll lastDigit = (d0 + d1) % 10;
        ll sum = d0 + d1 + lastDigit;
        ll remDigits = K - 3;
        if (K == 2)
        {
            if (sum % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        else
        {
            while (remDigits > 0)
            {
                if (lastDigit == 6)
                {
                    ll pattern = remDigits / 4;
                    sum += pattern * 20;
                    remDigits -= pattern * 4;

                    if (remDigits == 1)
                    {
                        sum += 2;
                    }
                    else if (remDigits == 2)
                    {
                        sum += 6;
                    }
                    else if (remDigits == 3)
                    {
                        sum += 14;
                    }
                    remDigits = 0;
                    break;
                }
                else if (lastDigit == 0)
                {
                    remDigits = 0;
                    break;
                }
                else
                {
                    lastDigit = (lastDigit * 2) % 10;
                    sum += lastDigit;
                    remDigits--;
                }
            }
            if (sum % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}