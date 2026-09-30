from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def build(start: Optional[ListNode], end: Optional[ListNode]):
            if start == end:
                return None

            slow = start
            fast = start

            # Fast pointer moves twice as fast to locate the middle node (slow)
            while fast != end and fast.next != end:
                slow = slow.next
                fast = fast.next.next

            # Middle element becomes the root
            root = TreeNode(slow.val)

            # Recursively construct left and right subtrees
            root.left = build(start, slow)
            root.right = build(slow.next, end)

            return root

        return build(head, None)