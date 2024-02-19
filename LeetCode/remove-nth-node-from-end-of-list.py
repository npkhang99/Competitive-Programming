# https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    class Integer:
        """
        The Integer class is used for persitance increment of how many nodes we are from the tail
        """
        def __init__(self, value=0):
            self.value = value

    def remove(self, head, n, from_end: Integer):
        if head is None:
            return

        self.remove(head.next, n, from_end)
        from_end.value += 1

        if from_end.value == n + 1:
            head.next = head.next.next

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None

        from_end = self.Integer()
        self.remove(head, n, from_end)
        if from_end.value == n:
            return head.next

        return head
