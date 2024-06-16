#include <iostream>
long revNum(long);
int main() {
    long num = 12345;
    long ans = revNum(num);
    std::cout << "Reverse of " << num << " : " << ans << std::endl;
}

long revNum(long n) { // time: O(log10 N) N number of digists in n, space : O(1)
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}