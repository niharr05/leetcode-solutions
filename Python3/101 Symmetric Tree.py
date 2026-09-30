# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def isMirror(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
            # Both nodes are empty -> mirror match
            if not t1 and not t2:
                return True

            # One node is empty or values differ -> not symmetric
            if not t1 or not t2 or t1.val != t2.val:
                return False

            # Cross-compare left against right and right against left
            return isMirror(t1.left, t2.right) and isMirror(t1.right, t2.left)

        return isMirror(root.left, root.right)