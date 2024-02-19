# https://leetcode.com/problems/linked-list-cycle/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False

        hare = head
        tortoise = head
        while hare is not None and tortoise is not None:
            if hare.next is None:
                return False

            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return True

        return False
