#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int ptr1 = m-1, ptr2 = 0;
    while (ptr1 >= 0 && ptr2 < n) {
        if (nums2[ptr2] < nums1[ptr1]) {
            swap(&nums2[ptr2], &nums1[ptr1]);
            ptr2++;
            ptr1--;
        }
        else
            break;
    }
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());
    for (int i = 0; i<n; i++) {
        nums1[m + i] = nums2[i];
    }
}

int getceil(int num) {
    if (num % 2 == 0)
        return num/2;
    return (num/2) + 1;
}

void mergeOpt(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int gap = getceil(m+n);
    int i, j;
    for (int i = 0; i<n; i++) {
        nums1[m + i] = nums2[i];
    }
    while (gap > 0) {
        i = 0;
        j = gap;
        while (j < m+n) {
            if (nums1[j] < nums1[i]) {
                swap(&nums1[i], &nums1[j]);
            }
            i++;
            j++;
        }
        if (gap == 1)
            break;
        gap = getceil(gap);
    }
}

int main() {
    vector<int> nums1 = {1,2,4,5,6,0};
    vector<int> nums2 = {3};
    int m = 5, n = 1, i;
    mergeOpt(nums1, m, nums2, n);
    for (i = 0; i<m+n; i++) {
        cout << nums1[i] << " ";
    }
}