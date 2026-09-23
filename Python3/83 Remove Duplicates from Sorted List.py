# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        while curr and curr.next:
            if curr.val == curr.next.val:
                # Bypass the duplicate node
                curr.next = curr.next.next
            else:
                # Move to the next unique node
                curr = curr.next

        return head