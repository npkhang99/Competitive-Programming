# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """
    Main idea is:
    - The preorder list will be our current node value
    - Find the index of that value in the inorder list => that will be our current sub-tree "root"
    - From "root" to the left will be the left sub-tree, from "root" to the right will be the right sub-tree
    """
    def build(self, pre_index: int, in_start: int, in_end: int, preorder: List[int], inorder: List[int]) -> TreeNode:
        if in_start >= in_end:
            return None

        value = preorder[pre_index]
        node = TreeNode(value)
        node_index = inorder.index(value, in_start, in_end)

        node.left = self.build(pre_index + 1, in_start, node_index, preorder, inorder)
        node.right = self.build(pre_index + (node_index - in_start) + 1, node_index + 1, in_end, preorder, inorder)

        return node

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        return self.build(0, 0, len(inorder), preorder, inorder)
