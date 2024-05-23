/*
Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.
*/
#include <iostream>
#include <vector>
using namespace std;
void permuteUtil(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, vector<int> used) {
    if (curr.size() == nums.size()) {
        ans.push_back(curr);
    }

    for (int i = 0; i<nums.size(); i++) {
        if (used[i] == 0) {
            curr.push_back(nums[i]);
            used[i] = 1;
            permuteUtil(nums, ans, curr, used);
            // Backtracking step (Important)
            used[i] = 0;
            curr.pop_back();
        }
    }
}

// Time complexity: O(N! x N), Space complexity:    O(N)
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    int n = nums.size();
    vector<int> used;
    for(int i = 0; i<n; i++) used.push_back(0);
    permuteUtil(nums, ans, curr, used);
    return ans;
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permuteOptimalUtil(int idx, vector<vector<int>> &ans, vector<int> &nums) {
    if (idx == nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i<nums.size(); i++) {
        swap(&nums[idx], &nums[i]);
        permuteOptimalUtil(idx+1, ans, nums);
        swap(&nums[idx], &nums[i]);
    }
}

vector<vector<int>> permuteOptimal(vector<int> &nums) {
    vector<vector<int>> ans;
    permuteOptimalUtil(0, ans, nums);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = permuteOptimal(nums);
    for (int i=0; i<ans.size(); i++) {
        for(int j = 0 ;j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}