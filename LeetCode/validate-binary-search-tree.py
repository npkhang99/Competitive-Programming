# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

INF = 10**18

class Solution:
    def validate(self, root, less_than, greater_than):
        if root == None:
            return True

        if root.val >= less_than or root.val <= greater_than:
            return False

        return self.validate(root.left, root.val, greater_than) and self.validate(root.right, less_than, root.val)

    def isValidBST(self, root: TreeNode) -> bool:
        return self.validate(root, INF, -INF)
