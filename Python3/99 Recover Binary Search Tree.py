# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """Do not return anything, modify root in-place instead."""
        self.first = None
        self.second = None
        self.prev = None

        def inorder(node: Optional[TreeNode]):
            if not node:
                return

            # Traverse left subtree
            inorder(node.left)

            # Process current node
            if self.prev and self.prev.val > node.val:
                # First time finding an inversion
                if not self.first:
                    self.first = self.prev
                # Update second every time an inversion is found
                self.second = node

            self.prev = node

            # Traverse right subtree
            inorder(node.right)
        inorder(root)
        # Swap the values of the two mismatched nodes
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val