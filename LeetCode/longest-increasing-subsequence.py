# https://leetcode.com/problems/longest-increasing-subsequence/description/
from bisect import bisect_left
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = [nums[0]]
        for num in nums[1:]:
            if lis[-1] < num:
                lis.append(num)
                continue

            pos = bisect_left(lis, num)
            lis[pos] = num

        return len(lis)
