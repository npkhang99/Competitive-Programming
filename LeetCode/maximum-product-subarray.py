# https://leetcode.com/problems/maximum-product-subarray/description/
from typing import List


class Solution:
    INF = 1_000_000_000

    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        current = nums[0]
        first_negative = -self.INF if nums[0] > 0 else nums[0]
        for num in nums[1:]:
            if current == 0:
                current = 1
                first_negative = -self.INF

            current *= num
            ans = max(ans, current if current > 0 or first_negative == -self.INF else current // first_negative)

            if num < 0 and first_negative == -self.INF:
                first_negative = current

        return ans
