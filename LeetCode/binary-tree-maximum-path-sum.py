# https://leetcode.com/problems/binary-tree-maximum-path-sum/
from typing import Optional, Union


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """
    Overral idea is like max subarray sum problem
    Returns 2 values:
    - The first value the max value of continuous_sum which includes the current node
    - The second value is the current maximum (the answer)
    """
    def find_max(self, node: Optional[TreeNode]) -> Union[int, int]:
        if node is None:
            return (0, -10**9)

        (max_branch_left, max_left) = self.find_max(node.left)
        (max_branch_right, max_right) = self.find_max(node.right)

        combined_sum = node.val + max(0, max_branch_left + max_branch_right)
        max_branch = node.val + max(max_branch_left, max_branch_right)

        overall_max = max(combined_sum, max_branch, max_left, max_right)

        # reset max_branch if negative, same idea as resetting current_sum in continuous subarray sum
        if max_branch < 0:
            max_branch = 0

        return (max_branch, overall_max)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return self.find_max(root)[1]
