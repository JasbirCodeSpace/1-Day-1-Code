#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src, dest, weight;
};

class Node{
    public:
        int parent;
        int rank;
};

int Find(Node nodes[], int x);
void Union(Node nodes[], int x, int y);
int compEdge(const void* a, const void* b);

class Graph{
    private:
        Edge* edge;
        int V;
        int E;
    public:
        Graph(int V, int E){
            edge = new Edge[E];
            this->V = V;
            this->E = E;
        }
        void createEdge(int i, int u, int v, int w){
            edge[i].src = u;
            edge[i].dest = v;
            edge[i].weight = w; 
        }
        void kruskalMST(){
            Edge res[V];
            qsort(edge, E, sizeof(edge[0]), compEdge);

            Node* nodes = new Node[V];
            for(int i=0;i<V;i++){
                nodes[i].parent = i;
                nodes[i].rank = 0;
            }
            int v = 0;
            for(int i=0;v<V-1 && i<E;i++){
                int x = Find(nodes, edge[i].src);
                int y = Find(nodes, edge[i].dest);
                if(x!=y){
                    res[v++] = edge[i];
                    Union(nodes, x, y);
                }
            }

            printMST(res);
        }

        void printMST(Edge res[]){

            int minCost = 0;
            for(int i=0; i<V-1; i++){
                cout<<res[i].src<<"-->"<<res[i].dest<<" = "<<res[i].weight<<'\n';
                minCost += res[i].weight;
            }
            cout<<"Minimum cost = "<<minCost<<'\n';
        }

};

int main(int argc, char const *argv[])
{

    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph graph(V, E);
 
    // add edge 0-1
    graph.createEdge(0, 0, 1, 10);
 
    // add edge 0-2
    graph.createEdge(1, 0, 2, 6);
 
    // add edge 0-3
    graph.createEdge(2, 0, 3, 5);
 
    // add edge 1-3
    graph.createEdge(3, 1, 3, 15);
 
    // add edge 2-3
    graph.createEdge(4, 2, 3, 4);
    
    graph.kruskalMST();
    return 0;
}

int Find(Node nodes[], int x){
    if(nodes[x].parent != x)
        nodes[x].parent = Find(nodes, nodes[x].parent);
    return nodes[x].parent;
}

void Union(Node nodes[], int x, int y){

    int xroot = Find(nodes, x);
    int yroot = Find(nodes, y);

    if(nodes[xroot].rank < nodes[xroot].rank)
        nodes[xroot].parent = yroot;
    else if(nodes[yroot].rank < nodes[xroot].rank)
        nodes[yroot].parent = xroot;
    else{
        nodes[yroot].parent = xroot;
        nodes[xroot].rank++;
    }
}

int compEdge(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}