#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(int a[], int b[], int n, int r){
    ll tension = b[0];
    ll max_tension = b[0];
    for (int i = 1; i < n; i++)
    {
        tension -= (a[i] - a[i-1])*r;
        if(tension<0)tension = 0;
        tension += b[i];
        max_tension = max(max_tension, tension);
    }
    return max_tension;
    
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;

        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int b[n];
        for(int i=0;i<n;i++)cin>>b[i];

        cout<<solve(a, b, n, r)<<'\n';        
        
    }
    return 0;
}