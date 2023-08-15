#include <iostream>
#include <vector>

// Memoization table to store computed Fibonacci values.
std::vector<long long> memo;

// Function to calculate the nth Fibonacci term using recursion and memoization.
long long fibonacci(int n) {
    // Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1.
    if (n <= 1) {
        return n;
    }

    // If the value is already computed, return it from the memoization table.
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calculate Fibonacci(n) using recursive calls with memoization.
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Initialize the memoization table with -1.
    memo.assign(n + 1, -1);

    // Calculate the nth Fibonacci term.
    long long result = fibonacci(n);

    std::cout << "The " << n << "th Fibonacci term is: " << result << std::endl;

    return 0;
}
