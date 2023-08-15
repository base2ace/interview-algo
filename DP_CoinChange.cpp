#include <iostream>
#include <vector>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1); // Initialize dp table with a value greater than amount.
    dp[0] = 0; // Base case: zero coins needed to make amount 0.

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] <= amount ? dp[amount] : -1; // Return -1 if amount cannot be made up.
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;

    int minCoins = coinChange(coins, amount);

    if (minCoins != -1) {
        std::cout << "Minimum number of coins needed: " << minCoins << std::endl;
    } else {
        std::cout << "Amount cannot be made up using the given coins." << std::endl;
    }

    return 0;
}
