#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#define N 10000
#define RANGE (int)1e6

void countingSort(int arr[], int len);

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
    countingSort(arr, len);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    elapsed.tv_sec  = end.tv_sec - start.tv_sec;
    
    printf ("%lf\n", 1000 * elapsed.tv_sec + elapsed.tv_nsec / 1e6);
    return 0;
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
