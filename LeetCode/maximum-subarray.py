# https://leetcode.com/problems/maximum-subarray/description/
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        current = 0
        for num in nums:
            if current < 0:
                current = 0

            current += num
            ans = max(ans, current)
        return ans
