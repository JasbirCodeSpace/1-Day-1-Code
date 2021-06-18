#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int b[n];
        
        for(int i=0; i<n ;i++)cin>>b[i];
        
        int sum = 0;
        for(int i=0; i<n ;i++){
            sum += b[i];
        }
        
        if(n == sum){
            cout<<0<<'\n';
        }else{
            if(sum<n)cout<<1<<'\n';
            else cout<<sum-n<<'\n';
        }
    }
    return 0;
}