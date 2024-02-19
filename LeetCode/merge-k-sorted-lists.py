# https://leetcode.com/problems/merge-k-sorted-lists/description/
from typing import Optional, List
import heapq


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        for i in range(len(lists)):
            if lists[i] is not None:
                heapq.heappush(min_heap, (lists[i].val, i))

        head = None
        tail = None
        while len(min_heap) > 0:
            val, i = heapq.heappop(min_heap)
            if lists[i].next is not None:
                lists[i] = lists[i].next
                heapq.heappush(min_heap, (lists[i].val, i))

            node = ListNode(val)
            if tail is None:
                head = tail = node
            else:
                tail.next = node
                tail = tail.next

        return head
