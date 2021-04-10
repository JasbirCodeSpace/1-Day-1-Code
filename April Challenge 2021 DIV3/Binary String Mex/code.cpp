#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
constexpr int MAX = int(1e6);
int num0[MAX], num1[MAX];
int dp0[MAX+2], dp1[MAX+2];

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
       if(s[i] == '0'){
           for (int j = pos+1; j <= i; j++)
           {
               num0[j] = i;
           }
           pos = i;
           
       }
    }

    for (int i = pos+1; i < n; i++)
    {
        num0[i] = n;
    }
    if(num0[0]==n){
        cout<<"0\n";
        return;
    }
    
    pos = -1;
    for (int i = 0; i < n; i++)
    {
       if(s[i] == '1'){
           for (int j = pos+1; j <= i; j++)
           {
               num1[j] = i;
           }
           pos = i;
           
       }
    }

    for (int i = pos+1; i < n; i++)
    {
        num1[i] = n;
    }
    
    dp0[n] = dp0[n+1] = 0;
    dp0[n] = dp0[n+1] = 0;
    for (int i = n-1; i>=0; i--)
    {
       dp0[i] = dp0[i+1];
       if(s[i] == '0' && num1[i]<n)dp0[i] = max(dp0[i], dp0[num1[i]+1]+1);
       if(s[i] == '1' && num0[i]<n)dp0[i] = max(dp0[i], dp0[num0[i]+1]+1);

       dp1[i] = dp1[i+1];
       if(num1[i]<n)
       dp0[i] = max(dp1[i], dp0[num1[i]+1]+1);
    }

    int len = dp1[0]+1;
    int cur = num1[0]+1;
    string ans = "1";
    for (int i = 0; i < len; i++)
    {
        if(cur>=n){
            ans.push_back('0');
            continue;
        }
        if(num0[cur]>=n){
            ans.push_back('0');
            cur = num0[cur]+1;
            continue;
        }
        if(dp0[num0[cur]+1] < len-i-1){
            ans.push_back('0');
            cur = num0[cur]+1;
        }else{
            ans.push_back('1');
            cur = num1[cur]+1;
        }
    }
    
    cout<<ans<<'\n';
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
