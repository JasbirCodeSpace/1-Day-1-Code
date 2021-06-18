#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        if(n&1)
            cout<<"Bob";
        else{
            int i=0;
            while((n&1) == 0){
                n = n >> 1;
                i++;
            }
            if(n>1)
                cout<<"Alice";
            else{
                if(i&1)
                    cout<<"Bob";
                else
                    cout<<"Alice";
            }
        }
        cout<<'\n';
    }
}