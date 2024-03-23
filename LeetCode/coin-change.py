# https://leetcode.com/problems/coin-change/description/
from typing import List


class Solution:
    INF = 1_000_000_000

    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [self.INF] * (amount + 1)
        dp[0] = 0
        coins = sorted(coins)
        for money in range(amount + 1):
            if dp[money] == self.INF:
                continue

            for coin in coins:
                if coin + money > amount:
                    break
                dp[money + coin] = min(dp[money + coin], dp[money] + 1)

        return -1 if dp[amount] == self.INF else dp[amount]
