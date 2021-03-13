#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Node{
    int vertex;
    struct Node* next;
};
struct Graph{
    int totalVertices;
    struct Node **adjList;
    int *visited;
};

// Node functions
struct Node* createNode(int v);

// Graph functions
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int start, int end);
void dfs();
void dfsUtil(int v);

void readFile();
void writeFile();
struct Graph* graph;
FILE* fptr = NULL;
int main(){
    readFile();
    writeFile();
}

struct Node* createNode(int v){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->totalVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int* )malloc(vertices*sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int start, int end){
    
    // add edge from start to end
    struct Node* node = createNode(end);
    node->next = graph->adjList[start];
    graph->adjList[start] = node;

    // add edge from end to start
    node = createNode(start);
    node->next = graph->adjList[end];
    graph->adjList[end] = node;
}

void dfs(){
    printf("\nDFS for given graph :: ");
    for(int i = 0; i < graph->totalVertices; i++)
        if(graph->visited[i] == 0)
            dfsUtil(i);
    
}

void dfsUtil(int v){
    graph->visited[v] = 1;
    printf("%d ", v);
    fprintf(fptr, "%d ", v);
    struct Node* temp = graph->adjList[v];
    while(temp){
        int adj_vertex = temp->vertex;
        if(graph->visited[adj_vertex] == 0){
            graph->visited[adj_vertex] = 1;
            dfsUtil(adj_vertex);
        }
        temp = temp->next;
    }
}

void readFile(){

    fptr = fopen("input.txt", "r");
    int total_vertices, start, end;
    fscanf(fptr, "%d", &total_vertices);
    graph = createGraph(total_vertices);

    while (!feof(fptr))
    {       
        fscanf(fptr, "%d", &start);
        fscanf(fptr, "%d", &end); 
        addEdge(graph, start, end);  
    }
    fclose(fptr);
}

void writeFile(){
    fptr = fopen("output.txt", "w");
    dfs();
    fclose(fptr);
}