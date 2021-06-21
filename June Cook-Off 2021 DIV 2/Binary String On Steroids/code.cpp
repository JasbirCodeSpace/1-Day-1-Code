#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int zero=0, one=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1')one++;
        else zero++;
    }

    vector<int> factors;

    for(int i=1; i<=sqrt(n); i++){

        if(n%i==0){
            if(n/i == i){
                factors.push_back(i);
            }
            else{
                factors.push_back(n/i);
                factors.push_back(i);
            }
        }
    }

    int res = INT_MAX;

    for(auto factor: factors){
        vector<int> freq(factor);

        for (int i = 0; i < factor; i++)
        {
           for (int j = i; j < n; j+=factor)
           {
               if(s[j]=='1')freq[i]++;
           }
           
        }

        int req = n/factor;
        for(int i=0; i<factor;i++){

            int c = req - freq[i];
            c += one-freq[i];
            res = min(c, res);
        }
        
    }

    cout<<res<<endl;
}
int main(){

    FAST1;
    FAST2;

    int t;
    cin>>t;
    while(t--){

        solve();
    }
}