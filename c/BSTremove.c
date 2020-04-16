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
Node* rightmostNode(Node* node);
Node* removeKey(int key, Node* tree);

int main(){
    int arr[N];
    int len = N;
    int num;

    FILE* input = fopen("array.txt", "r");
    for (int i = 0; i < N; i++){
        int s = fscanf(input, "%d", &num);
        arr[i] = num;
    }


    Node *root = NULL;


    for (int i = 0; i < N; i ++){
        root = insert(arr[i], root);
    }
    
    clock_t start, end;
    double insert_time;
    start = clock();
    for (int i = 0; i < N; i++){
        removeKey(arr[i], root);
    }
    end = clock();
    insert_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", insert_time * 1000);

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

Node* rightmostNode(Node* node){
    Node* current = node;
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

Node* removeKey(int key, Node* tree){
    if (tree == NULL){
//        printf("There is no node with key %d\n", key);
        return tree;
    }
    if (tree->key > key){
        tree->left = removeKey(key, tree->left);
    }
    else if (tree->key < key){
        tree->right = removeKey(key, tree->right);
    }
    else{ // node to be deleted is current node

        if (tree->left == NULL){ // node has only right child
            Node *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL){  // node has only left child
            Node *temp = tree->left;
            free(tree);
            return temp;
        }
        else{ // node has two children
            // find inorder predeessor, copy the content to the node to be deleted
            // removeKey inorder predecessor
            Node *temp = rightmostNode(tree->left);
            tree->key = temp->key;
            tree->left = removeKey(temp->key, tree->left);
        }
    }
    return tree;
}
