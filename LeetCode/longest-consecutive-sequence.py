# https://leetcode.com/problems/longest-consecutive-sequence/
from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        num_set = set(nums)
        for left in num_set:
            if left - 1 in num_set:
                continue
            
            right = left
            while right + 1 in num_set:
                right = right + 1
            ans = max(ans, right - left + 1)
        return ans
