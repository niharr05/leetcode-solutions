# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def buildTree(
        self, inorder: list[int], postorder: list[int]
    ) -> Optional[TreeNode]:
        inorder_index_map = {val: idx for idx, val in enumerate(inorder)}

        def build(in_left: int, in_right: int) -> Optional[TreeNode]:
            if in_left > in_right:
                return None

            # The last element in postorder is the root of current subtree
            root_val = postorder.pop()
            root = TreeNode(root_val)

            # Get index of root_val in inorder traversal
            index = inorder_index_map[root_val]

            # Construct right subtree before left subtree
            root.right = build(index + 1, in_right)
            root.left = build(in_left, index - 1)

            return root

        return build(0, len(inorder) - 1)