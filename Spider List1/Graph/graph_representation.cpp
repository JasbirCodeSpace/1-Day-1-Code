#include<bits/stdc++.h>
using namespace std;

/*
    Adjacency List
    Space complexity: O(V+E)
    Worst case O(V^2) as edge can be C(V, 2)
*/
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){

    for (int i = 0; i < V; i++)
    {
        cout<<i<<"|->";
        for(auto x: adj[i])
            cout<<x<<"->";
        cout<<"NULL"<<endl;
    }
    
}
int main(int argc, char const *argv[])
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
