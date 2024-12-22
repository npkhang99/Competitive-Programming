# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
from typing import List


class Solution:
    def findNextLocalMin(self, p: int, prices: List[int]) -> int:
        if p >= len(prices) or p == -1:
            return -1

        for i in range(p, len(prices)):
            if (
                (i < len(prices) - 1 and prices[i] <= prices[i + 1] and i == 0)
                or (i > 0 and prices[i - 1] >= prices[i] and i == len(prices) - 1)
                or prices[i - 1] >= prices[i] < prices[i + 1]
            ):
                return i

        return -1

    def findNextLocalMax(self, p: int, prices: List[int]) -> int:
        if p >= len(prices) or p == -1:
            return -1

        for i in range(p, len(prices)):
            if (
                (i < len(prices) - 1 and prices[i] >= prices[i + 1] and i == 0)
                or (i > 0 and prices[i - 1] <= prices[i] and i == len(prices) - 1)
                or prices[i - 1] <= prices[i] > prices[i + 1]
            ):
                return i

        return -1

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        i = 0
        buy = 0
        sell = 0
        ans = 0
        while i < len(prices):
            buy = self.findNextLocalMin(i, prices)
            sell = self.findNextLocalMax(buy + 1, prices)

            if buy == -1 or sell == -1:
                break

            ans += prices[sell] - prices[buy]
            i = sell + 1
        return ans
