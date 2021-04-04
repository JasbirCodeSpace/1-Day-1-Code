#include<iostream>
#include<string>
using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t;
    cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        int count = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            if(s[i] == '*')count++;
            else count=0;
            if(count == k){
                cout<<"YES";
                break;
            }
        }
        if(count != k)cout<<"NO";
        cout<<'\n';
        
    }
    return 0;
}
