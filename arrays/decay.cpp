#include <iostream>
using namespace std;

void pass_by_reference(int (&arr)[6]) {
    cout << "Pass by reference: size = " << sizeof(arr)/sizeof(int) << endl;
}

void arr_decay(int *arr) {
    cout << "Array decay: size= " << sizeof(arr) << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(int);

    cout << "Actual size: " << size << endl;

    pass_by_reference(arr);
    arr_decay(arr);
}