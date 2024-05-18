/*
Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

Examples:

Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]

Output: 6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Time: O(N*N) and space : O(1)*/
int trap(vector<int> &arr) {
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0 ;i<n; i++) {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0) {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;

        while (j < n) {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += (min(leftMax, rightMax) - arr[i]);
    }

    return waterTrapped;
}

int optmialTrap(vector<int> &arr) {
    int n = arr.size();
    int waterTrapped = 0;
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i<n; i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }
    suffix[n-1] = arr[n-1];
    for (int i = n -2; i>=0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    for(int i = 0; i<n; i++) {
        waterTrapped += min(prefix[i], suffix[i] - arr[i]);
    }
    return waterTrapped;
}

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trapWater = trap(heights);
    cout << "Water trapped: " << trapWater << endl;
}