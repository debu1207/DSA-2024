#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxPro = INT32_MIN, minPrice = 10001;
    for (int i = 0; i<n; i++) {
        if (minPrice > prices[i])
            minPrice = prices[i];
        
        if (maxPro < prices[i] - minPrice)
            maxPro = prices[i] - minPrice;
    }
    return maxPro;
}
int main() {
    vector<int> nums = {7,1,5,3,6,4};
    cout << "max profit: " << maxProfit(nums);
}