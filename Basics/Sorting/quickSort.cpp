#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &, int, int);
vector<int> quicksort(vector<int>);
void qs(vector<int> &, int, int);
void swap(int *, int *);

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    arr = quicksort(arr);
    cout << "Quick sort: " << "\n";
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(vector<int> &arr, int low, int high) {
    int p = arr[low];
    int i = low , j = high;

    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }

        if (i < j) swap(&arr[i], &arr[j]);

    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex -1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quicksort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}