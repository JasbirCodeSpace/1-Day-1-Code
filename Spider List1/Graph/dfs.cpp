#include<bits/stdc++.h>
using namespace std;

/* 
    Time complexity: O(V+E)
    Space complexity: O(V)
*/
class Graph{
    private:
    map<int, list<int>> adj;
    map<int, bool> visited;
    void DFSUtil(int v){
        visited[v] = true;
        cout<<v<<" ";
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
                DFSUtil(*i);
        }
        
    }

    public:
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void DFS(){

        for (auto u: adj)
        {
            if(!visited[u.first])
                DFSUtil(u.first);
        }
        
    }


};

int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "DFS: ";
    g.DFS();
 
    return 0; 
    return 0;
}
