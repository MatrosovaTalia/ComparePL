#include <iostream>
#include <string.h>
#include <chrono>
#define N 10000
#define RANGE 100000

using namespace std;


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

int main() {
    int arr[N];
    int len = N;
    int num;
    FILE *input = fopen("./array.txt", "r");
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &num);
        arr[i] = num;
    }
    auto start = std::chrono::steady_clock::now();

    countingSort(arr, len);

    auto end = std::chrono::steady_clock::now();
    
    std::chrono::duration<double> diff = end-start;

    cout << diff.count() * 1000 << endl;
    return 0;

}
