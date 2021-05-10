#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
class Graph{
    private:
        list<iPair> *adj;
        int V;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<iPair>[V];
        }
        void createEdge(int u, int v, int w){
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        void dijikstraSP(int src){

            vector<int> dist(V, INT_MAX);
            vector<bool> f(V, false);

            priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
            pq.push(make_pair(0, src));
            dist[src] = 0;
            while(!pq.empty()){
                int u = pq.top().second;
                pq.pop();
                f[u] = true;
                for(auto edge: adj[u]){
                    int v = edge.first;
                    int weight = edge.second;
                    if(f[v]==false && dist[v] > dist[u] + weight){
                        dist[v] = dist[u] + weight;
                        pq.push(make_pair(dist[v], v));
                    }

                }
            }

            for (int i = 0; i < V; i++)
            {
                cout<<i<<" : "<<dist[i]<<'\n';
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
    g.dijikstraSP(src); 
    return 0;
}
