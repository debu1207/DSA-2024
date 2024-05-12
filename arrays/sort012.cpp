#include <iostream>
#include <vector>
using namespace std;
void swap(int *, int *);
void sortColors(vector<int>&);
int main() {
    vector<int> nums = {2,0,2,1,1,0,0,1,2};
    sortColors(nums);
    for(int num: nums)
        cout << num << " ";
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(&nums[mid], &nums[high]);
            high--;
        }
    }
}