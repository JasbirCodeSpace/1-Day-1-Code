#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){

        int n, m;
        cin>>n>>m;

        int i, j;
        cin>>i>>j;

        if(i<=n/2 && j<=m/2)
            cout<<1<<" "<<m<<" "<<n<<" "<<1;
        else if(i>=n/2 && j>=m/2)
            cout<<1<<" "<<m<<" "<<n<<" "<<1;
        else
            cout<<1<<" "<<1<<" "<<n<<" "<<m;
        cout<<endl;
        
    }

    return 0;
}