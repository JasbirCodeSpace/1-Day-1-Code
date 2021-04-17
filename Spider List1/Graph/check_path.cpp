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

    bool isPathExist_BFS(int s, int d){

        if(s == d)return true;

        visited[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v = adj[u].begin(); v != adj[u].end(); v++)
            {
                if(d == *v)return true;
                if(!visited[*v]){
                    visited[*v] = true;
                    q.push(*v);
                }
            }
            
        }
        
        return false;
    }

    bool isPathExist_DFS(int s, int d){

        if(s == d)return true;
        visited[s] = true;
        stack<int> stk;
        stk.push(s);

        while(!stk.empty()){
            int u = stk.top();
            stk.pop();

            for (auto v = adj[u].begin(); v != adj[u].end(); v++)
            {
                if(d == *v)return true;
                if(!visited[*v]){
                    visited[*v] = true;
                    stk.push(*v);
                }
            }
            

        }
        return false;
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
    int u = 1, v = 3;
    if(g.isPathExist_DFS(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isPathExist_DFS(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
    return 0;
}
