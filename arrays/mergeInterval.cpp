#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) { // O(NlogN) + O(N)
    vector<vector<int>> ans; // Space complexity: O(N)
    sort(intervals.begin(), intervals.end()); // O(NLogN)
    ans.push_back(intervals[0]);
    int n = intervals.size();
    int last = 0;
    for (int i =1 ;i<n; i++) { // O(N)
        if (ans[last][1] >= intervals[i][0]) {
            if (ans[last][1] < intervals[i][1])
                ans[last][1] = intervals[i][1];
        }
        else {
            ans.push_back(intervals[i]);
            last++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,4},{2,3}};
    vector<vector<int>> ans = merge(intervals);
    int n = ans.size();
    for(int i = 0; i<n; i++) {
        cout << "[" << ans[i][0] << ", "<<ans[i][1] << "] ";
    }
}