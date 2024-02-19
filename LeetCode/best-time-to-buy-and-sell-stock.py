# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        ans = 0
        for price in prices[1:]:
            ans = max(ans, price - min_price)
            min_price = min(min_price, price)
        return ans
