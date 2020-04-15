#include <iostream>
#include <string.h>
#include <sys/time.h>
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
    timeval start, end;
    FILE *input = fopen("./array.txt", "r");
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &num);
        arr[i] = num;
    }
    gettimeofday(&start, NULL);

    countingSort(arr, len);

    gettimeofday(&end, NULL);
    timeval delta;
    delta.tv_sec = end.tv_sec - start.tv_sec;
    delta.tv_usec = end.tv_usec - start.tv_usec;

    cout << delta.tv_sec * 100000 + delta.tv_usec / 1e6 << endl;
    return 0;

}
