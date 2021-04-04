#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int a, b, c;
    cin>>a>>b>>c;

    (a == b || b == c || a == c)?cout<<"YES":cout<<"NO";
    return 0;
}
