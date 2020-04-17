#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
typedef struct node{
    int vertex;
    struct node* next;
}Node;

Node* createNode(int v);

typedef struct Graph{
    int numVertices;
    int* visited;
    struct node** adjLists;
}Graph;

Graph* createGraph(int);
void addEdge(Graph*, int, int);
void printGraph(Graph*);
void dfs(Graph*, int);


int main(){
    // create a full graph NxN
    Graph* graph = createGraph(N);
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            addEdge(graph, i, j);
        }
    }
   
    struct timespec start, end, elapsed;
    clock_gettime(CLOCK_REALTIME, &start);
    dfs(graph, 7);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    elapsed.tv_sec  = end.tv_sec - start.tv_sec;
    
    printf ("%lf\n", 1000 * elapsed.tv_sec + elapsed.tv_nsec / 1e6);
    
    return 0;
}

void dfs(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* current_node = adjList;
        
    graph->visited[vertex] = 1;
    
    while(current_node != NULL) {
        int nextVertex = current_node->vertex;
        
        if(graph->visited[nextVertex] == 0) {
            dfs(graph, nextVertex);
        }
        current_node = current_node->next;
    }       
}

 
Node* createNode(int v){
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(Node*));    
    graph->visited = malloc(vertices * sizeof(int));
 
    // set visited to 0 (not visited) 
    // set adjacency list to Null (empty list)
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(Graph* graph, int src, int dest){
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
 
void printGraph(Graph* graph){
    int v;
    for (v = 0; v < graph->numVertices; v++){
        Node* current_node = graph->adjLists[v];
        printf("\n Adjacent vertecies: %d\n ", v);
        while (current_node){
            printf("%d -> ", current_node->vertex);
            current_node = current_node->next;
        }
        printf("\n");
    }
}
