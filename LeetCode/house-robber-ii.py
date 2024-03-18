# https://leetcode.com/problems/house-robber-ii/description/
from typing import List


class Solution:
    def __rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        dp = [[0, 0] for i in range(len(nums))]
        dp[0][1] = dp[1][0] = nums[0]
        dp[1][1] = nums[1]
        for i in range(2, len(nums)):
            dp[i][0] = max(dp[i - 1])
            dp[i][1] = dp[i - 1][0] + nums[i]

        return max(map(max, dp))

    def rob(self, nums: List[int]) -> int:
        return max(self.__rob(nums[:-1]), self.__rob(nums[1:]))
