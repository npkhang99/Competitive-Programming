# https://leetcode.com/problems/insert-interval/
from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        new_interval_inserted = False
        new_intervals: List[List[int]] = []
        for interval in intervals:
            if interval[1] < newInterval[0]:
                new_intervals.append(interval)
                continue

            if newInterval[1] < interval[0]:
                if not new_interval_inserted:
                    new_intervals.append(newInterval)
                    new_interval_inserted = True
                new_intervals.append(interval)
                continue

            newInterval[0], newInterval[1] = min(interval[0], newInterval[0]), max(newInterval[1], interval[1])

        if not new_interval_inserted:
            new_intervals.append(newInterval)

        return new_intervals
