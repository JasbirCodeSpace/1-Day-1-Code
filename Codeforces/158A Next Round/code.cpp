#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin>>n>>k;

    int arr[n];
    for (size_t i = 0; i < n; i++)cin>>arr[i];

    int i = 0;
    while(true)
    {
        if(arr[i]>0 && arr[i]>=arr[k-1])i++;
        else break;
    }
    cout<<i<<'\n';
    return 0;
}
