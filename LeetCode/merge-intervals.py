# https://leetcode.com/problems/merge-intervals/description/
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda k: tuple(k))
        merged_intervals: List[List[int]] = []

        merged_interval = intervals[0]
        for interval in intervals[1:]:
            if merged_interval[0] <= interval[0] <= merged_interval[1]:
                merged_interval[1] = max(merged_interval[1], interval[1])
                continue

            merged_intervals.append(merged_interval)
            merged_interval = interval

        merged_intervals.append(merged_interval)
        return merged_intervals
