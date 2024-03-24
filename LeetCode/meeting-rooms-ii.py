# https://leetcode.com/problems/meeting-rooms-ii/
from typing import List


class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def get_conflicted(self, intervals: List[Interval]) -> List[Interval]:
        conflicted: List[Interval] = []
        picked = 0
        for i in range(1, len(intervals)):
            if intervals[picked].end <= intervals[i].start:
                picked = i
                continue
            conflicted.append(intervals[i])
        return conflicted

    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        if len(intervals) == 0:
            return 0

        intervals = sorted(intervals, key=lambda k: k.end)
        room_count = 1
        conflicted = self.get_conflicted(intervals)
        while len(conflicted) > 0:
            room_count += 1
            conflicted = self.get_conflicted(conflicted)
        return room_count
