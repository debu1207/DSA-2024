#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector <int> &, int, int); 
void merge(vector <int> &, int, int , int);
/*
Merge sort is a divide and conquer algorithm, it divides the given array into equal parts and then merges then 2 sorted parts.
*/

int main() {
    vector<int> arr = {4,2,1,6,7};
    int n = arr.size();
    mergesort(arr,0, n-1);
    for (int i = 0 ;i<n; i++) cout << arr[i] << " ";
}

void mergesort(vector<int> & arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void merge(vector<int> & arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    // storing elements in the temporary array in a sorted manner //
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }
    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}