#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};
class Graph{
    private:
    Edge* edge;
    int V;
    int E;

    public:
    Graph(int V, int E){
        edge = new Edge[E];
        this->E = E;
        this->V = V;
    }

    /*
        Time complexity: O(V*E)
        Space complexity: O(V)
    */
    void bellmanFord(int src){

        int dist[V];

        for (size_t i = 0; i < V; i++)dist[i] = INT_MAX;
        dist[src] = 0;

        int u, v, w;
        for (int i = 1; i < V; i++)
            for(int j = 0; j < E; j++){
                u = edge[j].src;
                v = edge[j].dest;
                w = edge[j].weight;
                if(dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }

        for(int i=0; i < E; i++){
            u = edge[i].src;
            v = edge[i].dest;
            w = edge[i].weight;

            if(dist[v] > dist[u] + w){
                cout<<"Negative cycle detected\n";
                return;
            }
        }
        
        cout<<"src : dest"<<'\n';
        for(int i=0; i<V; i++){
            cout<<i<<" : "<<dist[i]<<'\n';
        }
    }

    void createGraph(){

    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = -1;
  
    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 4;
  
    edge[2].src = 1;
    edge[2].dest = 2;
    edge[2].weight = 3;
  
    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 2;
  
    edge[4].src = 1;
    edge[4].dest = 4;
    edge[4].weight = 2;
  
    edge[5].src = 3;
    edge[5].dest = 2;
    edge[5].weight = 5;
  
    edge[6].src = 3;
    edge[6].dest = 1;
    edge[6].weight = 1;
  
    edge[7].src = 4;
    edge[7].dest = 3;
    edge[7].weight = -3;
    }

};

int main(int argc, char const *argv[])
{
    int V = 5;
    int E = 8;
    Graph g(V, E);
    g.createGraph();

    int src = 0;
    g.bellmanFord(0);

    return 0;
}
