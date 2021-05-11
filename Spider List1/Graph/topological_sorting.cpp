#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }

        void createEdge(int u, int v){
            adj[u].push_back(v);
        }

        void topologicalSort(){
            stack<int> stk;
            vector<bool> visited(V, false);

            for (int u = 0; u < V; u++)
            {
                if(!visited[u])
                    topologicalSortUtil(u, visited, stk);
            }
            
            while(!stk.empty()){
                cout<<stk.top()<<" ";
                stk.pop();
            }
        }

        void topologicalSortUtil(int u, vector<bool>& visited, stack<int>& stk){

            visited[u] = true;
            for(auto v: adj[u]){
                if(!visited[v])
                    topologicalSortUtil(v, visited, stk);
            }
            stk.push(u);
        }
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.createEdge(5, 2);
    g.createEdge(5, 0);
    g.createEdge(4, 0);
    g.createEdge(4, 1);
    g.createEdge(2, 3);
    g.createEdge(3, 1);
    g.topologicalSort();
    return 0;
}
