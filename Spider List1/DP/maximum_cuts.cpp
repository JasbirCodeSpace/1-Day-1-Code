#include<iostream>
using namespace std;

// Time: O(3^n)
int maxCuts1(int n, int a, int b, int c){
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    
    int res = max( maxCuts1(n-a, a, b, c), max( maxCuts1(n-b, a, b, c), maxCuts1(n-c, a, b, c)));
    
    return res==-1?res:res+1;
    
}
/*
    Time: O(N)
    Space: O(N)
*/
int maxCuts2(int n, int a, int b, int c){

    int dp[n+1];
    fill(dp, dp+n+1, -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        if(i-a>=0)
            dp[i] = max(dp[i], dp[i-a]+1);
        if(i-b>=0)
            dp[i] = max(dp[i], dp[i-b]+1);
        if(i-c>=0)
            dp[i] = max(dp[i], dp[i-c]+1);
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n = 10, a = 5, b = 3, c = 4;
    cout<<maxCuts2(n, a, b, c)<<endl;
    return 0;
}
