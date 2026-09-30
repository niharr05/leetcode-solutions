from collections import deque
from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def levelOrderBottom(
        self, root: Optional[TreeNode]
    ) -> List[List[int]]:
        if not root:
            return []

        result = []
        q = deque([root])

        while q:
            level_size = len(q)
            current_level = []

            for _ in range(level_size):
                curr = q.popleft()
                current_level.append(curr.val)

                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)

            result.append(current_level)

        # Reverse to get bottom-up order
        return result[::-1]