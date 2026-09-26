# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def partition(
        self, head: Optional[ListNode], x: int
    ) -> Optional[ListNode]:
        # Dummy heads to keep track of the start of both lists
        before_head = ListNode(0)
        after_head = ListNode(0)

        # Pointers to traverse/append to the two lists
        before = before_head
        after = after_head

        curr = head
        while curr:
            if curr.val < x:
                before.next = curr
                before = before.next
            else:
                after.next = curr
                after = after.next
            curr = curr.next

        # Crucial step: cut off any leftover pointer at the end of 'after' list
        after.next = None

        # Connect the two lists together
        before.next = after_head.next

        return before_head.next