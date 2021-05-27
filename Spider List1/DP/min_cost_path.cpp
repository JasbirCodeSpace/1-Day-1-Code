#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z);
int minCostPathRec(int cost[R][C], int m, int n); // O(2^n)
int minCostPath(int cost[R][C], int m, int n);  // O(mn)
int main(int argc, char const *argv[])
{
    int cost[R][C] = { { 1, 2, 3 },
                       { 4, 8, 2 },
                       { 1, 5, 3 } };
    cout<<minCostPath(cost, R, C)<<endl;
    return 0;
}

int minCostPath(int cost[R][C], int m, int n){

    // first row
    for(int i=1; i<n; i++)
        cost[0][i] += cost[0][i-1];
    
    // first column
    for(int i=1; i<m; i++)
        cost[i][0] += cost[i-1][0];
    
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            cost[i][j] += min(cost[i-1][j-1], cost[i-1][j], cost[i][j-1]);
            
    return cost[m-1][n-1];
}
int minCostPathRec(int cost[R][C], int m, int n){
    if(m<0 || n<0)
        return INT_MAX;
    else if(m==0 && n==0)
        return cost[m][n];
    else{
        return cost[m][n] + min(minCostPathRec(cost, m-1, n-1),
                                minCostPathRec(cost, m, n-1),
                                minCostPathRec(cost, m-1, n));
    }
}

int min(int x, int y, int z){
    if(x<y)
        return (x<z)?x:z;
    else
        return (y<z)?y:z;
}
