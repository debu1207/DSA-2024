#include <iostream>
#include <cmath>
#include <algorithm>

int digitCount(long num) { // time: O(log 10 N + 1) , space : O(1)
    int c = 0;
    while(num) {
        c++;
        num/=10;
    }
    return c;
}

int optimal(long num) { // time: O(1), space : O(1)
    int res = (int)(log10(num) + 1);
    return res;
}

int main() {
    long n = 12345;
    // std::cout << digitCount(n) << std::endl;
    std::cout << optimal(n) << std::endl;
}