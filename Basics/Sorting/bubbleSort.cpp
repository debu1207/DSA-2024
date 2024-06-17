#include <iostream>
using namespace std;

void bubble(int [], int);
void swap(int *, int *);

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr, n);
    for (int i = 0 ;i<n; i++) cout << arr[i] << " ";
}

void bubble(int arr[], int n) { // time complexity: o(N*N), space : O(1)
    for (int i = n ; i > 0; i--) {
        for (int j = 0; j<i-1; j++) {
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}