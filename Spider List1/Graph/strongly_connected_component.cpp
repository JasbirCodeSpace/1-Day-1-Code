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

        Graph transpose(){
            Graph g(V);

            for (int i = 0; i < V; i++)
            {
                for(auto v: adj[i]){
                    g.createEdge(v, i);
                }
            }
            
            return g;
        }

        void dfs1(int u, vector<bool>& visited, stack<int>& stk){

            visited[u] = true;
            for (auto v = adj[u].begin(); v != adj[u].end(); v++)
            {
                if(!visited[*v])
                    dfs1(*v, visited, stk);
            }
            stk.push(u);
        }

        void dfs2(int u, vector<bool>& visited){

            visited[u] = true;
            cout<<u<<" ";
            for(auto v = adj[u].begin(); v != adj[u].end(); v++){
                if(!visited[*v])
                    dfs2(*v, visited);
            }
        }

        void scc(){
            vector<bool> visited(V, false);
            stack<int> stk;

            for (int i = 0; i < V; i++)
            {
                if(!visited[i])
                    dfs1(i, visited, stk);
            }

            Graph revG = transpose();
            fill(visited.begin(), visited.end(), false);

            while(!stk.empty()){
                int u = stk.top();
                stk.pop();
                if(!visited[u]){
                    revG.dfs2(u, visited);
                    cout<<'\n';
                }
            }   
        }

        void printGraph(){

            for (int i = 0; i < V; i++)
            {
                cout<<i<<" : ";
                for(auto v: adj[i])
                    cout<<" ->"<<v;
                cout<<'\n';
            }
            
        }
};

int main(int argc, char const *argv[])
{
    Graph g(5);
    g.createEdge(1, 0);
    g.createEdge(0, 2);
    g.createEdge(2, 1);
    g.createEdge(0, 3);
    g.createEdge(3, 4);
  
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.scc();
    return 0;
}
