#include <iostream>

int fibonacciRecursive(int n) {
    // Base cases: fib(0) = 0, fib(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Calculate the nth term of the Fibonacci sequence using recursion.
    int nthTerm = fibonacciRecursive(n);

    std::cout << "The " << n << "th term of the Fibonacci sequence is: " << nthTerm << std::endl;

    return 0;
}
