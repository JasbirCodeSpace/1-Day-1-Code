#include<bits/stdc++.h>
using namespace std;

enum Color{
    WHITE, RED, GREEN
};

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
            adj[v].push_back(u);
        }

        bool dfsUtil(int u, Color* colors){

            for(auto v: adj[u]){
                if(colors[v] == WHITE){
                    (colors[u] == RED)?colors[v] = GREEN:colors[v] = RED;
                    dfsUtil(v, colors);
                }
                else if(colors[v] == colors[u])
                    return false;
            }
            return true;
        }
        bool isBipartite_dfs(){
            Color colors[V];
            for (int i = 0; i < V; i++)
                colors[i] = WHITE;

            colors[0] = RED;

            for (int i = 0; i < V; i++)
            {
                if(colors[i] == WHITE){
                    if(!dfsUtil(i, colors))
                        return false;
                }
            }
            return true;
        }

        bool isBipartite_bfs(){
            
            int src = 0;
            Color colors[V];
            for(int i=0; i<V; i++)
                colors[i] = WHITE;
            
            queue<int> q;

            colors[src] = RED;
            q.push(src);

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v: adj[u]){
                    if(colors[v] == WHITE){
                        (colors[u] == RED)?colors[v] = GREEN:colors[v] = RED;
                        q.push(v);
                    }else if(colors[u] == colors[v]){
                        return false;
                    }
                }
            }
            return true;

        }

};

int main(int argc, char const *argv[])
{
    int V = 6;
    Graph g(V);
    g.createEdge(0, 1);
    g.createEdge(1, 2);
    g.createEdge(2, 3);
    g.createEdge(3, 4);
    g.createEdge(4, 5);
    g.createEdge(5, 0);

    if(g.isBipartite_bfs())
        cout<<"Given graph is bipartite\n";
    else
        cout<<"Given graph is not bipartite\n";
    return 0;
}
