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
        for (int j = 0; j < N; j++){
            addEdge(graph, i, j);
        }
    }

    // for (int i = 0; i < N - 1; i++){
    //     for (int j = i + 1; j < N; j++){
    //         addEdge(graph, i, j);
    //     }
    // }

    
    // printGraph(graph);
    clock_t start, end;
    double insert_time;
    start = clock();
    dfs(graph, 100);
    end = clock();

    double bfs_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", bfs_time);
    
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
