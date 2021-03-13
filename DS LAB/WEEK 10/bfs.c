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
struct Queue{
    int arr[SIZE];
    int front;
    int rear;
};

// Node functions
struct Node* createNode(int v);

// Graph functions
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int start, int end);
void bfs(int source);

// Queue functions
struct Queue* createQueue();
void enqueue(struct Queue* q, int v);
int dequeue(struct Queue* q);
void display(struct Queue* q);
int isEmpty(struct Queue* q);
void printQueue(struct Queue* q);

void readFile();
void writeFile(int source);
struct Graph* graph;
FILE* fptr = NULL;
int main(){
    int source;
    readFile();
    printf("\nEnter source node :: ");
    scanf("%d", &source);
    writeFile(source);
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

void bfs(int source){
    struct Queue* q = createQueue();
    graph->visited[source] = 1;
    enqueue(q, source);
    printf("\nBFS for given graph :: ");
    while(!isEmpty(q)){
        int v = dequeue(q);
        fprintf(fptr, "%d ", v);
        printf("%d ", v);

        struct Node* temp = graph->adjList[v];
        while(temp){
            int adj_vertex = temp->vertex;
            if(graph->visited[adj_vertex] == 0){
                graph->visited[adj_vertex] = 1;
                enqueue(q, adj_vertex);
            }
            temp = temp->next;
        }
    }
}

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q){
    if(q->rear == -1)return 1;
    return 0;
}

void enqueue(struct Queue* q, int v){
    if(q->rear == SIZE-1){
        printf("\nQueue is full");
    }else{
        if(q->front == -1)q->front = 0;
        q->rear += 1;
        q->arr[q->rear] = v;
    }
    return;
}

int dequeue(struct Queue* q){
    int v;
    if(isEmpty(q)){
        printf("\nQueue is empty");
        return -1;
    }else{
        v = q->arr[q->front];
        q->front += 1;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
    }
    return v;
}

void printQueue(struct Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is empty");
        return;
    }
    printf("Queue :: ");
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
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

void writeFile(int source){
    fptr = fopen("output.txt", "w");
    bfs(source);
    fclose(fptr);
}