#include <iostream>
#include <sys/time.h>
#define N 10000
using namespace std;

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


int main() {
    int arr[N];
    int len = N;
    int num;
    FILE *input = fopen("array.txt", "r");
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &num);
        arr[i] = num;
    }

    timeval start, end;
    gettimeofday(&start, NULL);

    insertionSort(arr, len);

    gettimeofday(&end, NULL);
    timeval delta;
    delta.tv_sec = end.tv_sec - start.tv_sec;
    delta.tv_usec = end.tv_usec - start.tv_usec;

    cout << delta.tv_sec * 1000 + delta.tv_usec / 1e4 << endl;
}
