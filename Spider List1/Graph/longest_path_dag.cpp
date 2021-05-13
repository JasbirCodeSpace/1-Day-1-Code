#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

class Graph{
    private:
        int V;
        list<iPair> *adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<iPair>[V];
        }

        void createEdge(int u, int v, int w){
            adj[u].push_back(make_pair(v, w));
        }

        void topologicalUtil(int u, vector<bool>& visited, stack<int>& stk){

            visited[u] = true;
            for(auto i: adj[u]){
                if(!visited[i.first])
                    topologicalUtil(i.first, visited, stk);
            }

            stk.push(u);
        }

        void longestPathDAG(int s){

            vector<bool> visited(V, false);
            stack<int> stk;
            vector<int> dist(V, INT_MIN);

            for(int i=0; i<V; i++){
                if(!visited[i])
                    topologicalUtil(i, visited, stk);
            };

            dist[s] = 0;
            while (!stk.empty())
            {
                int u = stk.top();
                stk.pop();

                if(dist[u] == INT_MIN)
                    continue;
                
                for(auto i: adj[u]){
                    int v = i.first;
                    int weight = i.second;
                    if(dist[v] < dist[u]+weight)
                        dist[v] = dist[u] + weight;
                }
            }

            for (int i = 0; i < V; i++)
            {
                cout<<i<<" : ";
                (dist[i] == INT_MIN)?cout<<"NINF":cout<<dist[i];
                cout<<'\n';
            }
            
            
        }
};
int main(int argc, char const *argv[])
{
    Graph g(6);
    g.createEdge(0, 1, 5);
    g.createEdge(0, 2, 3);
    g.createEdge(1, 3, 6);
    g.createEdge(1, 2, 2);
    g.createEdge(2, 4, 4);
    g.createEdge(2, 5, 2);
    g.createEdge(2, 3, 7);
    g.createEdge(3, 5, 1);
    g.createEdge(3, 4, -1);
    g.createEdge(4, 5, -2);
   
    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPathDAG(s);
    return 0;
}
