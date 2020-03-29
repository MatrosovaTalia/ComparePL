#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define N 1000

typedef struct queue {
    int items[SIZE];
    int front;
    int rear;
}Queue;

Queue* createQueue();
void enqueue(Queue* q, int);
int dequeue(Queue* q);
void display(Queue* q);
int isEmpty(Queue* q);
void printQueue(Queue* q);

typedef struct node{
    int vertex;
    struct node* next;
}Node;
Node* createNode(int);

typedef struct Graph{
    int numVertices;
    Node** adjLists;
    int* visited;
}Graph;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void bfs(Graph* graph, int startVertex);

int main(){
    // create a full graph NxN
    Graph* graph = createGraph(N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            addEdge(graph, i, j);
        }
    }
    // printGraph(graph);
    clock_t start, end;
    double insert_time;
    start = clock();
    bfs(graph, 100);
    end = clock();
    double dfs_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", dfs_time);
    return 0;
}

void bfs(Graph* graph, int startVertex) {

    Queue* q = createQueue();
    
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while(!isEmpty(q)){
        int currentVertex = dequeue(q);
        // printf("Visited %d\n", currentVertex);
    
       Node* temp = graph->adjLists[currentVertex];
    
       while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
       }
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
 
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(Queue* q) {
    if(q->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Queue* q, int value){
    if(q->rear == SIZE-1){
        return;
    }
        // printf("\nQueue is Full!!");
    else {
        if(q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q){
    int item;
    if(isEmpty(q)){
        // printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            // printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}
