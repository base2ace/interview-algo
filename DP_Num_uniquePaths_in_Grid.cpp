#include <iostream>
#include <vector>

// Memoization table to store computed paths
std::vector<std::vector<int>> memo;

int uniquePaths(int m, int n, int row, int col) {
    // Check if out of bounds
    if (row >= m || col >= n) {
        return 0;
    }

    // Base case: destination reached
    if (row == m - 1 && col == n - 1) {
        return 1;
    }

    // If already computed, return the value from memoization
    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    // Compute the unique paths by moving right and down
    int rightPaths = uniquePaths(m, n, row, col + 1);
    int downPaths = uniquePaths(m, n, row + 1, col);

    // Store the computed result in memoization
    memo[row][col] = rightPaths + downPaths;

    return memo[row][col];
}

int main() {
    int m = 3; // Number of rows
    int n = 3; // Number of columns

    // Initialize the memoization table with -1
    memo.assign(m, std::vector<int>(n, -1));

    int totalPaths = uniquePaths(m, n, 0, 0);

    std::cout << "Total unique paths: " << totalPaths << std::endl;

    return 0;
}
