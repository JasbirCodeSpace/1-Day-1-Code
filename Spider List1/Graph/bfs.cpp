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

    public:
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void BFS(int s){
        visited[s] = true;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            cout<<u<<" ";
            q.pop();

            for (auto v = adj[u].begin(); v!=adj[u].end(); v++)
            {
                if(!visited[*v]){
                    visited[*v] = true;
                    q.push(*v);
                }
            }
            
        }
        
    }
};
int main(int argc, char const *argv[])
{   
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "BFS (starting from vertex 2): ";
    g.BFS(2);    
    return 0;
}
