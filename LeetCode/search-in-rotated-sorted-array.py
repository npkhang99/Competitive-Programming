# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
from typing import List

INF = 10**4 + 1


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid

            """
            Assume nums = [4, 5, 6, 7, 0, 1, 2]
            Let say target = 2 we can consider nums = [-INF, -INF, -INF, -INF, 0, 1, 2]
                    targer = 6 we can consider nums = [4, 5, 6, 7, INF, INF, INF]
            After that, we can perform binary search as usual
            """
            mid_val = nums[mid]
            if nums[left] <= nums[mid] and nums[left] > target:
                mid_val = -INF
            if nums[mid] <= nums[right] and target > nums[right]:
                mid_val = INF

            if mid_val < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1
