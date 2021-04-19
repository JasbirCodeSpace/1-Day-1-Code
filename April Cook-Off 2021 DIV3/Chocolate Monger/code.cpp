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
        int n,x;
        cin>>n>>x;

        int c[n];
        for(int i=0;i<n;i++)cin>>c[i];

        set<int> s;
        for (int i = 0; i < n; i++)s.insert(c[i]);

        int dist = s.size();
        if(dist <= n-x)cout<<dist<<'\n';
        else cout<<n-x<<'\n';
        
    }
    return 0;
}
