#include <iostream>
#include <vector>
using namespace std;

bool valid(int row, int col, vector<string> &board, int n) {
    // cout << "checking valid position";
    // left
    int r = row, c = col;
    while (c >= 0) {
        if (board[r][c] == 'Q') 
            return false;
        c --;
    }
    // upper left diagonal
    r = row, c =col;
    while (r >=0 && c >=0) {
        if (board[r][c] == 'Q') 
            return false;
        r --;
        c --;
    }
    // lower left diagonal
    r = row, c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q') 
            return false;
        r ++;
        c --;
    }
    // cout << "Valid position";
    return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row<n; row++) {
        if (valid(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '-';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '-');

    for (int i = 0; i<n; i++)
        board[i] = s;
    
    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n=4;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i<ans.size(); i++) {
        for (int j = 0 ;j<n; j++) {
            cout << ans[i][j] << "\n";
        }
        cout << endl; 
    }
}