#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll n){

    int sum1[4] = {20, 36, 51, 60};
    if(n<=4)return sum1[n-1];

    int partial = n % 4;
    ll complete = (n - partial)/4;
    ll completeSum = complete * 44;

    int sum2[4] = {16, 32, 44, 55};
    completeSum += sum2[partial];
    return completeSum;

}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll result = solve(n);
        cout<<result<<'\n';
    }
    return 0;
}
