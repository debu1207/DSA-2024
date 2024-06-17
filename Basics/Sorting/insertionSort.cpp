#include <iostream>
using namespace std;

void insertion(int [], int);
void swap(int *, int *);

int main() {
    int arr[] = {5, 4, 3, 2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    for (int i = 0 ;i<n; i++) cout << arr[i] << " ";
}

void insertion(int arr[], int n) { // time complexity: O(N*N) and space complexity: O(1)
    int j;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            j = i;
            while (j>=0 && arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                j--;
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}