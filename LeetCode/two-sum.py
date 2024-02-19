# https://leetcode.com/problems/two-sum
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hist = {}
        for i in range(len(nums)):
            delta = target - nums[i]
            if delta in hist:
                return [hist[delta], i]
            hist[nums[i]] = i
        return []
