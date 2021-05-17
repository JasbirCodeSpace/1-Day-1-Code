#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define NIL -1
#define MAX 100
ll lookup[MAX];

ll fib(ll n);
void initialize();
ll fibMemoization(ll n);                  // Top-Down Approach
ll fibTabulation(ll n);                   // Bottom-Up Approach
int main(int argc, char const *argv[])
{
    ll n = 50, res;
    time_t start, end;

    time(&start);
    initialize();
    res = fib(n);
    time(&end);

    cout<<"\nRescursion";
    cout<<"\nFactorial of "<<n<<" : "<<res;
    cout<<"\nTime taken: "<<fixed<<double(end - start)<<setprecision(5);

    time(&start);
    initialize();
    res = fibMemoization(n);
    time(&end);
    cout<<"\nTop Down Approach"<<'\n';
    cout<<"\nFactorial of "<<n<<" : "<<res;
    cout<<"\nTime taken: "<<fixed<<double(end - start)<<setprecision(5);

    time(&start);
    initialize();
    res = fibTabulation(n);
    time(&end);
    cout<<"\nBottom Up Approach"<<'\n';
    cout<<"\nFactorial of "<<n<<" : "<<res;
    cout<<"\nTime taken: "<<fixed<<double(end - start)<<setprecision(5);
    return 0;

    return 0;
}

ll fib(ll n){
    if(n<=1)return n;
    return fib(n-1)+fib(n-2);
}
void initialize(){
    for (ll i = 0; i < MAX; i++)
        lookup[i] = NIL;
}

ll fibMemoization(ll n){
    if(lookup[n]==NIL){
        if(n<=1)
            lookup[n] = n;
        else
            lookup[n] = fibMemoization(n-1)+fibMemoization(n-2);
    }
    return lookup[n];
}

ll fibTabulation(ll n){

    ll f[n+1];
    f[0] = 0;
    f[1] = 1;
    for (ll i = 2; i < n; i++)
        f[i] = f[i-1] + f[i-2];
    
    return f[n];
}