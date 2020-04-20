#include <iostream>
#include <chrono>
#define N 10000
using namespace std;

void insertionSort(int arr[], int len){
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
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

    auto start = chrono::steady_clock::now();

    insertionSort(arr, len);

    auto end = chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;

    cout << diff.count() * 1000 << endl;
}
