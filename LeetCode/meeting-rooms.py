# https://leetcode.com/problems/meeting-rooms/
from typing import List


class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        timeline = [0] * 1001
        for interval in intervals:
            timeline[interval.start] += 1
            timeline[interval.end] -= 1

        cumulative_sum = 0
        for i in range(len(timeline)):
            cumulative_sum += timeline[i]
            if cumulative_sum > 1:
                return False

        return True
