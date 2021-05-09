#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dest;
};

class Node{
    public:
        int parent, rank;
};

class Graph{
    private:
        int V, E;
        Edge* edge;
    public:
        Graph(int V, int E){
            this->V = V;
            this->E = E;
            edge = new Edge[E];
        }

        void createEdge(int i, int u, int v){
            edge[i].src = u;
            edge[i].dest = v;
        }

        int Find(Node nodes[], int x){
            if(nodes[x].parent != x){
                nodes[x].parent = Find(nodes, nodes[x].parent);
            }
            return nodes[x].parent;
        }

        void Union(Node nodes[], int x, int y){
            int xroot = Find(nodes, x);
            int yroot = Find(nodes, y);

            if(nodes[xroot].rank < nodes[yroot].rank)
                nodes[xroot].parent = yroot;
            else if(nodes[xroot].rank > nodes[yroot].rank)
                nodes[yroot].parent = xroot;
            else{
                nodes[yroot].parent = xroot;
                nodes[xroot].rank++;
            }

        }

        bool isCycle(){
            Node* nodes = new Node[V];
            for (int i = 0; i < V; i++)
            {
                nodes[i].parent = i;
                nodes[i].rank = 0;
            }

            for (int i = 0; i < E; i++)
            {
                int x = Find(nodes, edge[i].src);
                int y = Find(nodes, edge[i].dest);
                if(x == y)return true;
                Union(nodes, x, y);
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
