#include <iostream>
#include <sys/time.h>
#define N 10000
using namespace std;

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


void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, len - 1);

    gettimeofday(&end, NULL);
    timeval delta;
    delta.tv_sec = end.tv_sec - start.tv_sec;
    delta.tv_usec = end.tv_usec - start.tv_usec;

    cout << delta.tv_sec * 1000 + delta.tv_usec / 1e6 << endl;
}
