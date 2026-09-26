# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def generateTrees(self, n: int) -> list[Optional[TreeNode]]:
        if n == 0:
            return []

        def generate(start: int, end: int) -> list[Optional[TreeNode]]:
            if start > end:
                return [None]

            all_trees = []

            # Try every number in the range [start, end] as the root
            for i in range(start, end + 1):
                # Generate all left and right subtrees recursively
                left_trees = generate(start, i - 1)
                right_trees = generate(i + 1, end)

                # Connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        root = TreeNode(i)
                        root.left = l
                        root.right = r
                        all_trees.append(root)

            return all_trees

        return generate(1, n)