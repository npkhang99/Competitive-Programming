# https://leetcode.com/problems/kth-smallest-element-in-a-bst/
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Integer:
    def __init__(self, val):
        self.value = val


class Solution:
    def traverse(self, root: Optional[TreeNode], k: int, cnt: Integer) -> int:
        if root is None:
            return -1

        val = self.traverse(root.left, k, cnt)
        if cnt.value == k:
            return val

        cnt.value += 1
        if cnt.value == k:
            return root.val

        val = self.traverse(root.right, k, cnt)
        if cnt.value == k:
            return val

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        return self.traverse(root, k, Integer(0))
