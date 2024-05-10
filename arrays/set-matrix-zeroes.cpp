#include <iostream>
using namespace std;

void print(int array[3][4], int r, int c) {
    for (int i = 0; i< r; i++) {
        for (int j = 0; j<c; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void brute(int arr[3][4], int r, int c) {
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            if (arr[i][j] == 0) {
                for (int k = 0; i<c; i++) {
                    if (arr[i][k] != 0) {
                        arr[i][k] = -1;
                    }
                }
                for (int k = 0; i<r; i++) {
                    if (arr[k][j] != 0) {
                        arr[k][j] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
    print(arr, r,c);
}

void optimal1(int arr[3][4], int row, int col) {

    int cols[4] = {};
    int rows[3] = {};

    for (int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            if (arr[i][j] == 0){
                cols[j] = 1;
                rows[i] = 1;
            }
        }
    }
    for (int i = 0; i<row; i++) {
        for(int j = 0; j<col;j++) {
            if (arr[i][j] != 0) {
                if (cols[j] == 1 || rows[i] == 1) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    cout << "Calling print: \n";
    print(arr, row, col);
}

int main() {
    int arr[3][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int cols = 4, rows = 3;
    cout << "Original matrix: \n";
    print(arr, rows, cols);
    cout << "Brute force Result: \n";
    brute(arr, rows, cols);

    cout << "Optimal 1 result: \n";
    optimal1(arr, rows, cols);
    return 0;
}