#include <iostream>
#include <vector>
using namespace std; 

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(vector<int>& row, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        swap(&row[l], &row[r]);
        l++;
        r--;
    }
}

void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();
    // transpose matrix
    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    // reverse each row
    for (int i = 0; i<n; i++) {
        reverse(matrix[i], n);
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    int n = matrix.size();
    for(int i =0 ;i< n; i++) {
        for(int j = 0; j<n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}