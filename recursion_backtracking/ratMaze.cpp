#include <iostream>
#include <vector>
using namespace std;

void findPath(vector<vector<int>> &maze, vector<vector<int>> &vis, int x, int y, int n, vector<string> &ans, string move) {
    if (x == n-1 && y == n-1) {
        ans.push_back(move);
        return;
    }

    // downward
    if (x + 1 < n && !vis[x+1][y] && maze[x+1][y] == 1) {
        vis[x+1][y] = 1;
        findPath(maze, vis, x + 1, y, n, ans, move + 'D');
        vis[x+1][y] = 0;
    }
    // left
    if (y - 1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1) {
        vis[x][y-1] = 1;
        findPath(maze, vis, x, y - 1, n, ans, move + 'L');
        vis[x][y-1] = 0;
    }
    // upward
    if (x - 1 > 0 && !vis[x-1][y] && maze[x-1][y] == 1) {
        vis[x-1][y] = 1;
        findPath(maze, vis, x - 1, y, n, ans, move + 'U');
        vis[x-1][y] = 0;
    }
    // right
    if (y + 1 < n && !vis[x][y+1] && maze[x][y+1] == 1) {
        vis[x][y+1] = 1;
        findPath(maze, vis, x, y + 1, n, ans, move + 'R');
        vis[x][y+1] = 0;
    }
}

int main() {
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans;
    int n = 4;
    vector < vector < int >> vis(n, vector < int > (n, 0));
    findPath(maze, vis, 0, 0, n, ans, "");

    if (ans.size() > 0) {
        for (int i = 0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
}