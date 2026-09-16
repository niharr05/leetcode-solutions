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
private:
  // Helper function to get the kth node from the current starting node
  ListNode *getKthNode(ListNode *curr, int k) {
    while (curr != nullptr && k > 1) {
      curr = curr->next;
      k--;
    }
    return curr;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    ListNode dummy(0, head);
    ListNode *prevGroupHead = &dummy;

    while (true) {
      // Find the kth node of the current group
      ListNode *kthNode = getKthNode(prevGroupHead->next, k);
      if (!kthNode)
        break; // Less than k nodes left, leave as is

      ListNode *nextGroupHead = kthNode->next;
      ListNode *curr = prevGroupHead->next;
      ListNode *prev = nextGroupHead;

      // Reverse the k nodes in-place
      while (curr != nextGroupHead) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      }

      // Connect the reversed group back to the main list
      ListNode *temp = prevGroupHead->next;
      prevGroupHead->next = kthNode;
      prevGroupHead = temp;
    }

    return dummy.next;
  }
};