# https://leetcode.com/problems/subtree-of-another-tree/description/
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def compareTree(self, node1: Optional[TreeNode], node2: Optional[TreeNode]) -> bool:
        if node1 is None or node2 is None:
            return node1 == node2

        return (
            node1.val == node2.val and
            self.compareTree(node1.left, node2.left) and
            self.compareTree(node1.right, node2.right)
        )

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None:
            return False

        is_same_tree = False
        if root.val == subRoot.val:
            is_same_tree = self.compareTree(root, subRoot)

        return is_same_tree or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
