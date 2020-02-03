#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000
#define RANGE 100

void insertionSort(int arr[], int len);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void countingSort(int arr[], int len);

int main(){
    int arr[N];
    int len = N;
    int num;
    FILE* outTime = fopen("time-measured.txt", "a");

    clock_t start, end;
    double insertion_time;
    double merge_time;
    double counting_time;

    FILE* input = fopen("array.txt", "r");
    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

//     FILE* out = fopen("arrayReverse.txt", "w");
//     for (int i = 0; i < N; i++){
//         fprintf(out, "%d ", arr[N - 1 - i]);
//     }
//     fclose(out);

    start = clock();
   insertionSort(arr, len);
    end = clock();

    insertion_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

    start = clock();
   mergeSort(arr, 0, len - 1);
    end = clock();

    merge_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

    start = clock();
    countingSort(arr, len);
    end = clock();

    counting_time = ((double) (end - start)) / CLOCKS_PER_SEC;

//
//    for (int i = 0; i < len; i++){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");

    fprintf(outTime, "Insertion sort time: %f\n"
                     "Merge sort time: %f\n"
                     "Counting sort time: %f\n", insertion_time, merge_time, counting_time);

    // printf("Hello, I am C file!\n");

    fclose(input);
    fclose(outTime);
    return 0;
}

void insertionSort(int arr[], int len){
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 & arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
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

void countingSort(int arr[], int len){
    int count[RANGE];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < len; i++){
        count[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < RANGE; i++){
        while(count[i] > 0){
            arr[k] = i;
            k++;
            count[i]--;
        }
    }
}

