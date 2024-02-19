# https://leetcode.com/problems/reverse-linked-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse_recursive(self, prevNode: ListNode, currentNode: ListNode) -> ListNode:
        if currentNode is None:
            return prevNode
        nextNode = currentNode.next
        currentNode.next = prevNode
        return self.reverse(currentNode, nextNode)

    def reverse_iterative(self, head: ListNode) -> ListNode:
        prevNode = None
        currentNode = head
        while currentNode is not None:
            nextNode = currentNode.next
            currentNode.next = prevNode
            prevNode = currentNode
            currentNode = nextNode
        return prevNode

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        return self.reverse_iterative(head)
