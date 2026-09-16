/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Dummy node points to head to simplify edge cases (e.g., deleting head)
    ListNode *dummy = new ListNode(0, head);
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // Advance fast pointer n + 1 steps ahead to create a gap of n nodes
    for (int i = 0; i <= n; ++i) {
      fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // Slow is now right before the node to be removed
    ListNode *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete; // Free memory

    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
  }
};