# https://leetcode.com/problems/binary-tree-level-order-traversal/
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def traverse(self, root: Optional[TreeNode], i: int, levels: List[List[int]]) -> None:
        if root is None:
            return

        while len(levels) <= i:
            levels.append([])

        levels[i].append(root.val)
        self.traverse(root.left, i + 1, levels)
        self.traverse(root.right, i + 1, levels)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        self.traverse(root, 0, levels)
        return levels
