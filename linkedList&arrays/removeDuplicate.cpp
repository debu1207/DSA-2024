/*
Remove Duplicate in-place from Sorted Array
Given an integer array sorted in non-decreasing order,
 remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

*/
#include<iostream>
#include <vector>
using namespace std;
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Time complexity: O(N)   Space complexity: O(1)*/
int removeDuplicate(vector<int> &nums) {
    int idx = 0, n = nums.size();
    if (n == 1)
        return nums[0];
    int prev = nums[idx];
    for (int i = 1 ;i<n; i++) {
        if (nums[i] != prev) {
            idx++;
            prev = nums[i];
            swap(&nums[i], &nums[idx]);
        }
    }
    return idx+1;
}

int main() {
    vector<int> arr = {1,1,2};
    int uniq = removeDuplicate(arr);
    cout << "Ans: " << uniq << endl;
}