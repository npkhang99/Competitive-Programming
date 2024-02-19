# https://leetcode.com/problems/merge-two-sorted-lists/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def append(self, head: Optional[ListNode], tail: Optional[ListNode], node: ListNode) -> ListNode:
        if head is None:
            return node

        tail.next = node
        tail = tail.next
        return tail

    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = None
        tail = None

        while list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                tail = self.append(head, tail, list1)
                list1 = list1.next
            else:
                tail = self.append(head, tail, list2)
                list2 = list2.next

            if head is None:
                head = tail

        while list1 is not None:
            tail = self.append(head, tail, list1)
            if head is None:
                head = tail
            list1 = list1.next

        while list2 is not None:
            tail = self.append(head, tail, list2)
            if head is None:
                head = tail
            list2 = list2.next

        return head
