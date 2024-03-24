# https://leetcode.com/problems/non-overlapping-intervals/description/
from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda k: k[1])

        pick_count = 1
        last_pick = 0
        for i in range(1, len(intervals)):
            if intervals[last_pick][1] <= intervals[i][0]:
                last_pick = i
                pick_count += 1
        return len(intervals) - pick_count
