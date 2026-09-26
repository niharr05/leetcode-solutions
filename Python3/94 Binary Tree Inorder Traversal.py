# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        res = []
        stack = []
        curr = root

        while curr or stack:
            # Step 1: Reach the leftmost node of the current node
            while curr:
                stack.append(curr)
                curr = curr.left

            # Step 2: Process current node
            curr = stack.pop()
            res.append(curr.val)

            # Step 3: Move to the right subtree
            curr = curr.right

        return res