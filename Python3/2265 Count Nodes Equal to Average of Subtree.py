# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        count = 0

        def dfs(node: Optional[TreeNode]) -> tuple[int, int]:
            nonlocal count

            if not node:
                return (0, 0)

            # Post-order DFS: process left and right children first
            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)

            # Aggregate current subtree stats
            total_sum = left_sum + right_sum + node.val
            total_count = left_count + right_count + 1

            # Check if subtree average matches node's value
            if total_sum // total_count == node.val:
                count += 1

            return (total_sum, total_count)

        dfs(root)
        return count