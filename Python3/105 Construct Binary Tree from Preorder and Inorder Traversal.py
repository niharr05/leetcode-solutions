# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def buildTree(
        self, preorder: list[int], inorder: list[int]
    ) -> Optional[TreeNode]:
        # Hash map for fast lookup of root index in inorder array
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        self.pre_idx = 0

        def arrayToTree(left_bound: int, right_bound: int) -> Optional[TreeNode]:
            if left_bound > right_bound:
                return None

            # Current root value from preorder traversal
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1

            root = TreeNode(root_val)
            idx = inorder_map[root_val]

            # Build left subtree before right subtree
            root.left = arrayToTree(left_bound, idx - 1)
            root.right = arrayToTree(idx + 1, right_bound)

            return root

        return arrayToTree(0, len(inorder) - 1)