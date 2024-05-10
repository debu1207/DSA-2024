#include <iostream>
#include <vector>
using namespace std;
vector<int> pascal_triangle_row(int);
void print_vec(vector<int>);

int main() {
    int rowNum;
    cout << "Enter pascal triangle row number: ";
    cin >> rowNum;
    vector<int> res = pascal_triangle_row(rowNum);
    print_vec(res);
}

void print_vec(vector<int> num) {
    for (int n: num) {
        std::cout << n <<" ";
    }
}

vector<int> pascal_triangle_row(int rowNum) {
    vector<int> ans;
    ans.push_back(1);
    if (rowNum == 1) {
        return ans;
    }
    int temp = 1;
    for (int i = 0; i<rowNum-1; i++) {
        temp = temp * (rowNum - i -1) / (i + 1);
        ans.push_back(temp);
    }
    return ans;
}