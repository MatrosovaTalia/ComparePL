#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 10000

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main(){
    int arr[N];
    int len = N;
    int num;
    FILE* input = fopen("array.txt", "r");
    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

    clock_t start, end;
    double insert_time;
    start = clock();

    mergeSort(arr, 0, len - 1);

    end = clock();
    insert_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", insert_time);

    return 0;
}



void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = arr[i + l];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[j + m + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}