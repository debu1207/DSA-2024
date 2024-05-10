#include <iostream>

int fib_recur(int);
int fib_dp(int);

int main(int argc, char *argv[]) {
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    std::cout << "Recursive Fibonacci number: " << fib_recur(n) << std::endl;
    std::cout << "DP Fibonacci number: " << fib_dp(n) << std::endl;
}

int fib_dp(int num) {
    if (num == 1 || num == 0)
        return 1;

    int x = 1, y = 1, t;
    for (int i = 2; i<= num; i++) {
        t = x;
        x += y;
        y = t;
    }
    return x;
}

int fib_recur(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    return fib_recur(num-1 ) + fib_recur(num-2);
}