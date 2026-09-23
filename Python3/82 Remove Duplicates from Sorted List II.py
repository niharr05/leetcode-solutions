# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(0, head)
        prev = dummy

        while prev.next and prev.next.next:
            # Check if current node and next node have the same value
            if prev.next.val == prev.next.next.val:
                dup_val = prev.next.val
                # Skip all nodes with this duplicate value
                while prev.next and prev.next.val == dup_val:
                    prev.next = prev.next.next
            else:
                # No duplicate, move pointer forward
                prev = prev.next

        return dummy.next