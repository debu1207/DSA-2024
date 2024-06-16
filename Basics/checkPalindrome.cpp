#include <iostream>

void isPalindrome(long);
long revNum(long);

int main() {
    long num = 4524;
    isPalindrome(num);
}

void isPalindrome(long n) {// time: O(log10 N) N number of digists in n, space : O(1)
    long rev = revNum(n);
    if (rev == n) std::cout << "Palindrome Number";
    else std::cout << "Not Palindrome";
}

long revNum(long n) { 
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}