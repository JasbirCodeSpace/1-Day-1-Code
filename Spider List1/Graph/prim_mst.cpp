#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph{
    private:
        int V, E;
        list<iPair> *adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<iPair>[V];
        }

        void createEdge(int u, int v, int w){
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        void primMST(int src){

            vector<int> key(V, INT_MAX);
            vector<int> parent(V, -1);
            vector<bool> inMST(V, false);

            priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
            pq.push(make_pair(0, src));
            key[src] = 0;

            while(!pq.empty()){

                int u = pq.top().second;
                inMST[u] = true;
                pq.pop();
                for(auto edge: adj[u]){
                    int v = edge.first;
                    int weight = edge.second;
                    if(inMST[v]==false && key[v]>weight){
                        key[v] = weight;
                        parent[v] = u;
                        pq.push(make_pair(key[v], v));
                    }
                }
                
            }

            for (int i = 0; i < V; i++)
            {
                if(i!=src){
                    cout<<parent[i]<<" "<<i<<" : "<<key[i]<<'\n';
                }
            }
            
        }
};

int main(int argc, char const *argv[])
{
    int V = 9;
    Graph g(V);
 
    g.createEdge(0, 1, 4);
    g.createEdge(0, 7, 8);
    g.createEdge(1, 2, 8);
    g.createEdge(1, 7, 11);
    g.createEdge(2, 3, 7);
    g.createEdge(2, 8, 2);
    g.createEdge(2, 5, 4);
    g.createEdge(3, 4, 9);
    g.createEdge(3, 5, 14);
    g.createEdge(4, 5, 10);
    g.createEdge(5, 6, 2);
    g.createEdge(6, 7, 1);
    g.createEdge(6, 8, 6);
    g.createEdge(7, 8, 7);
    
    int src = 0;
    g.primMST(src);  
    return 0;
}
