#include <iostream>
using namespace std;

#define MAX 10000

void swap(int *, int *);
void selectionSort(int [], int);

int main() {
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    for (int i = 0; i<n; i++) cout << arr[i] << " ";
}

void selectionSort(int arr[], int n) { // time complexity: O(N*N)
    int min = MAX;
    int midx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j<n; j++) {
            if (arr[j] < arr[midx]) {
                min = arr[j];
                midx = j;
            }
        }
        swap(&arr[i], &arr[midx]);
        min = MAX;
        midx = i+1;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}