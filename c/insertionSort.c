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

    FILE* input = fopen("./array.txt", "r");
    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

    struct timespec start, end, elapsed;
    clock_gettime(CLOCK_REALTIME, &start);
    insertionSort(arr, len);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    elapsed.tv_sec  = end.tv_sec - start.tv_sec;
    
    printf ("%lf\n", 1000 * elapsed.tv_sec + elapsed.tv_nsec / 1e6);
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
