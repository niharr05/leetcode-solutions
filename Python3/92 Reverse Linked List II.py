# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        if not head or left == right:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev_left = dummy

        # Step 1: Reach the node prior to 'left'
        for _ in range(left - 1):
            prev_left = prev_left.next

        # Step 2: Reverse the sublist in-place
        curr = prev_left.next
        for _ in range(right - left):
            then = curr.next
            curr.next = then.next
            then.next = prev_left.next
            prev_left.next = then

        return dummy.next