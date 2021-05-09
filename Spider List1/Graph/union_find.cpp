#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dest;
};

class Graph{
    private:
        int V, E;
        Edge* edge;
    public:
    Graph(int V, int E){
        edge = new Edge[E];
        this->V = V;
        this->E = E;
    }
    void createEdge(int i, int u, int v){
        edge[i].src = u;
        edge[i].dest;
    }
    int Find(int parent[], int x){
        if(parent[x] == x)
            return x;
        return Find(parent, parent[x]);  
    }

    void Union(int parent[], int x, int y){
        parent[x] = y;
    }

    bool isCycle(){

        int *parent = new int[V];
        for(int i=0; i<V; i++)
            parent[i] = i;

        for (int i = 0; i < E; i++)
        {
            int x = Find(parent, edge[i].src);  
            int y = Find(parent, edge[i].dest);
            if(x == y)
                return true;
            Union(parent, x, y);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;
    Graph graph(V, E);
 
    // add edge 0-1
    graph.createEdge(0, 0, 1);
 
    // add edge 1-2
    graph.createEdge(1, 1, 2);
 
    // add edge 0-2
    graph.createEdge(2, 0, 2);
 
    if (graph.isCycle())
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";   
    return 0;
}
