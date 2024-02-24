# https://leetcode.com/problems/find-median-from-data-stream/description/
import heapq


class MedianFinder:
    """
    Main idea is to maintains 2 heaps:
    - 1 lower_half max-heap
    - 1 upper_half min-heap
    When inserting, prioritize inserting into the lower_half heap but tries to balance the size of the 2 heaps
    so that the lower_half's size never exceeds (the upper_half's size + 1)
    """

    def __init__(self):
        self.lower_half = []
        self.upper_half = []

    def addNum(self, num: int) -> None:
        if len(self.lower_half) == 0 or -self.lower_half[0] >= num:
            heapq.heappush(self.lower_half, -num)
        else:
            heapq.heappush(self.upper_half, num)

        if len(self.lower_half) > len(self.upper_half) + 1:
            heapq.heappush(self.upper_half, -heapq.heappop(self.lower_half))
        elif len(self.lower_half) < len(self.upper_half):
            heapq.heappush(self.lower_half, -heapq.heappop(self.upper_half))

    def findMedian(self) -> float:
        if len(self.lower_half) == len(self.upper_half):
            return (-self.lower_half[0] + self.upper_half[0]) / 2
        return -self.lower_half[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
