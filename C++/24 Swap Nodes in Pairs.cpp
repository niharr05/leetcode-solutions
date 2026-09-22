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
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy(0, head);
    ListNode *prev = &dummy;

    // Traverse as long as there is a pair to swap
    while (prev->next != nullptr && prev->next->next != nullptr) {
      ListNode *first = prev->next;
      ListNode *second = prev->next->next;

      // Rewire pointers to swap first and second
      first->next = second->next;
      second->next = first;
      prev->next = second;

      // Move prev pointer forward for the next pair
      prev = first;
    }

    return dummy.next;
  }
};