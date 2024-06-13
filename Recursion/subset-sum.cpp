#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void subsetSumUtil(vector<int> &arr, vector<int> &ans, int N, int idx, int sum) {
    if (idx == N) {
        ans.push_back(sum);
        return;
    }

    // element is picked
    subsetSumUtil(arr, ans, N, idx + 1, sum + arr[idx]);
    // element is not picked
    subsetSumUtil(arr, ans, N, idx + 1, sum);
}

vector<int> subsetSum(vector<int> arr, int N) {
    vector<int> ans;
    subsetSumUtil(arr, ans, N, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr {5, 1, 2};
    vector<int> ans = subsetSum(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout << "Sum of each subset is : \n";
    for (int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}