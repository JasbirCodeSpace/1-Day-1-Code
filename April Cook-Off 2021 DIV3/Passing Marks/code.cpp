#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t;
    cin>>t;
    while(t--){
        int a_min, b_min, c_min, t_min, a, b, c;
        cin>>a_min>>b_min>>c_min>>t_min>>a>>b>>c;
        int sum = a + b + c;
        if(a>=a_min && b>=b_min && c>=c_min && sum>=t_min)cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
