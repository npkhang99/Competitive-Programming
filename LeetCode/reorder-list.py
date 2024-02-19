# https://leetcode.com/problems/reorder-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return head

        list_array = []
        it = head
        while it is not None:
            list_array.append(it)
            it = it.next

        left, right = 0, len(list_array) - 1
        while left < right:
            list_array[left].next = list_array[right]
            list_array[right].next = list_array[left + 1]
            left += 1
            right -= 1

        list_array[max(left, right)].next = None
        return list_array[0]
