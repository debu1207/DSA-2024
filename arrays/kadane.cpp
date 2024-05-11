#include <iostream>
#include <vector>
using namespace std;

int brute_maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxsum = INT32_MIN;
    for(int i = 0 ;i<n; i++) {
        for (int j = i; j< n; j++) {
            int sum = 0;
            for (int k = i; k<=j; k++) {
                sum += nums[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int optimal_maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxsum = INT32_MIN;
    for(int i = 0 ;i<n; i++) {
        int sum = 0;
        for (int j = i; j< n; j++) {   
            sum += nums[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int kadane_maxSubArray(vector<int>& nums) {
    int maxsum = INT32_MIN;
    int sum = 0;
    for (int i = 0 ;i< nums.size(); i++) {
        sum += nums[i];
        maxsum = max(sum, maxsum);
        if (sum < 0)
            sum = 0;
    }
    return maxsum;
}

void print_maxSubArray(vector<int>& nums) {
    int maxsum = INT32_MIN;
    int sum = 0;
    int l = -1, r = -1;
    for (int i = 0 ;i< nums.size(); i++) {
        if (sum == 0)
            l = i;
        sum += nums[i];
        if (maxsum < sum) {
            maxsum = sum;
            r = i;
        }
        if (sum < 0)
            sum = 0;
    }
    for (int i =l; i<=r; i++)
        cout << nums[i] << " ";
}

int main() {
    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
    // cout << "Max sum of subarray: " << brute_maxSubArray(nums);
    // cout << "Max sum of subarray: " << optimal_maxSubArray(nums);
    cout << "max sum of subarray: " << kadane_maxSubArray(nums) << endl;
    print_maxSubArray(nums);
}