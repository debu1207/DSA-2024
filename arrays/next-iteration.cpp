#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int just_large(vector<int> nums, int n, int num) {
    int ret = 0;
    for (int i = n-1; i>=0; i--) {
        if (nums[i] > num) {
            ret = i;
            break;
        }
    }
    return ret;
}

void reverse(vector<int> &nums, int l, int r) {
    while (l < r) {
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
}

void next_iteration(vector<int> &nums, int n) {
    int idx = 0;
    for (int i = n-2; i>= 0; i--) {
        if (nums[i] < nums[i+1]) {
            idx = i;
            break;
        }
    }
    int k = just_large(nums, n, nums[idx]);
    swap(&nums[idx], &nums[k]);
    reverse(nums, idx+1, n-1);
}

int main() {
    vector<int> nums= {2,1,5,4,3,0,0};
    int n = nums.size();
    next_iteration(nums, n);
    for (int num: nums)
        cout << num << " ";
}