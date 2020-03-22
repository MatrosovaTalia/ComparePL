#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 10000

void insertionSort(int arr[], int len);

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

    insertionSort(arr, len);

    end = clock();
    insert_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", insert_time);

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
