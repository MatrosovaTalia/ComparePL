#include <stdio.h>
#define N 1000

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
    insertionSort(arr, len);
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
