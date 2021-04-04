#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t;
    cin>>t;
    while(t--){
        double k1, k2, k3, v;
        cin>>k1>>k2>>k3>>v;

        double result = 100 / (k1*k2*k3*v);
        result = floor((result*100)+0.5)/100;
        (result < 9.58)?cout<<"YES":cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
