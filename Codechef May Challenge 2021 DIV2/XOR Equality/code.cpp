#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fastExponent(ll a, ll b, ll p){
    ll res = 1;
    a = a % p;
    if(a == 0)
        return 0;

    while(b>0){
        if(b&1)
            res = (res*a)%p;
        a = (a*a)%p;
        b = b>>1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll p = pow(10, 9)+7;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<fastExponent(2, n-1, p)<<'\n';
    }
    return 0;
}
