#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 10000

typedef struct node {
    int key;
    struct node *left;
    struct node *right;    
}Node;

Node* newNode (int key);
Node* insert(int newKey, Node* tree);
Node* findNode(int key, Node* tree);

int main(){
    int arr[N];
    int len = N;
    int num;

    double insert_time;
    // FILE* outTime = fopen("tree-results.txt", "a");

    FILE* input = fopen("array.txt", "r");
    for (int i = 0; i < N; i++){
        int s = fscanf(input, "%d", &num);
        arr[i] = num;
    }

    Node *root = NULL;    
    struct timespec start, end, elapsed;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < N; i ++){
        root = insert(arr[i], root);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    elapsed.tv_sec  = end.tv_sec - start.tv_sec;
    
    printf ("%lf\n", 1000 * elapsed.tv_sec + elapsed.tv_nsec / 1e6);
    return 0;
}

Node* insert(int newKey, Node* tree){
    if (findNode(newKey, tree) != NULL){
        return tree;
    }

    if (tree == NULL){
        return newNode(newKey);
    }
    if (tree->key > newKey){
        tree->left =  insert(newKey, tree->left);
    }
    else{
        tree->right = insert(newKey, tree->right);
    }
    return tree;
}

Node* findNode(int key, Node* tree){
    Node* current = tree;
    while (current != NULL){
        if (current->key == key){
            return current;
        }
        else if (current->key > key){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return NULL;
}

Node* newNode (int key){
    Node* temp = (Node*) malloc(sizeof(struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
