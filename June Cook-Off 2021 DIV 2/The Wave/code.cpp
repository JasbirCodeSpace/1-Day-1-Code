#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

int main(){
    
    FAST1;
    FAST2;

    int N, Q;
    cin>>N>>Q;

    int a[N];
    for(int i=0; i<N; i++)cin>>a[i];
    
    sort(a, a+N);
    
    while(Q--){
        int x;
        cin>>x;
        
        int i=lower_bound(a, a+N, x)-a;

        if(i<N && a[i]==x)
            cout<<0;
        else if(i&1)
            cout<<"NEGATIVE";
        else
            cout<<"POSITIVE";
        cout<<'\n';
    }
    return 0;
}