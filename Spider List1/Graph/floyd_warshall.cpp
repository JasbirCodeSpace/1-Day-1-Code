#include<bits/stdc++.h>
using namespace std;
#define V 4

void printMatrix(int M[][V]);
void floydWarshall(int graph[][V]);

int main(int argc, char const *argv[])
{
    int graph[V][V] = { { 0, 5, INT_MAX, 10 },
                        { INT_MAX, 0, 3, INT_MAX },
                        { INT_MAX, INT_MAX, 0, 1 },
                        { INT_MAX, INT_MAX, INT_MAX, 0 } }; 
    printMatrix(graph);
    floydWarshall(graph);  
    return 0;
}


/*
    Time complexity: O(V^3)
    Space complexity: O(V^2)
*/
void floydWarshall(int graph[][V]){

    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) 
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++){
                if((dist[i][j] > dist[i][k] + dist[k][j]) 
                    && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
    printMatrix(dist);
}

void printMatrix(int M[][V]){

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(M[i][j] == INT_MAX)
                cout<<"INF"<<"\t";
            else
                cout<<M[i][j]<<"\t";
        }
        cout<<'\n';
    }
    cout<<'\n';
}