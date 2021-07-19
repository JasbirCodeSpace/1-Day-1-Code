#include<bits/stdc++.h>
using namespace std;

// Time: O(n * n!)
void allPermute(string s, int l, int r){
    if(l==r){
        cout<<s<<" ";
        return;
    }
    for(int i=l; i<=r; i++){
        swap(s[i], s[l]);
        allPermute(s, l+1, r);
        swap(s[i], s[l]);
    }
}
int main(int argc, char const *argv[])
{
    
    string str = "ABC";
    int n = str.size();
    allPermute(str, 0, n-1);
    cout<<endl;
    return 0;
}
