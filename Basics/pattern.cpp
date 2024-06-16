#include <iostream>
using namespace std;

void rec(int r) {
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<r; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void triangle(int r) {
    for (int i = 0; i<r; i++) {
        for (int j = 0; j < i+1; j++)
            cout << "*" << " ";
        cout << endl;
    }
}

void col_triangle(int r) {
    for (int i = 1; i<=r; i++) {
        for (int j = 1; j<=i; j++) {
             cout << j << " ";
        }
        cout << endl;
    }
}

void row_triangle(int r) {
    for (int i = 1; i <=r ; i++) {
        for (int j = 1; j<=i; j++) cout << i << " ";
        cout << endl;
    }
}

void revtri(int r) {
    for (int i = r; i>0; i--) {
        for (int j = 1; j<=i; j++) cout << j << " ";
        cout << endl;
    }
}

void pyramid(int r) {
    for (int i = 0 ; i < r; i++) {
        for (int j = 0; j < r - i - 1; j++ ) cout << "  ";
        for (int k = 0; k < 2*i + 1; k++) cout << "* ";
        cout << endl;
    }
}

void revPyramid(int r) {
    for (int i = 0 ; i < r; i++) {
        for (int j = 0; j < i; j++ ) cout << "  ";
        for (int k = 0; k < 2*(r - i) - 1; k++) cout << "* ";
        cout << endl;
    }
}

void binTriangle(int r) {
    for (int i = 1 ;i<=r; i++) {
        for (int j = 1; j<=i; j++) {
            if ((i + j) % 2 == 0) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void patternM(int r) {
    for (int i = 1;i<=r; i++) {
        for (int j=1; j<=i; j++) cout << j << " ";

        for (int k = 0 ; k < 2*(r - i + 1) - 1; k++) cout << "  ";

        for (int j =i; j>=1; j--) cout << j << " ";

        cout << endl;
    }
}

void numPattern(int r) {
    int num = 1;
    for (int i = 0; i<r; i++) {
        for (int j = 0; j < i+1; j++)
            cout << num++ << " ";
        cout << endl;
    }
}

int main() {
    int r = 5;
    rec(r);
    // cout << endl;
    // triangle(r);
    // cout << endl;
    // col_triangle(r);
    // cout << endl;
    // row_triangle(r);
    // cout << endl;
    revtri(r);
    cout << endl;;
    pyramid(r);
    cout << endl;
    revPyramid(r);
    cout << endl;
    binTriangle(r);
    cout << endl;
    patternM(r);
    cout << endl;
    numPattern(r);
}