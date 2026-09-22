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
  ListNode *rotateRight(ListNode *head, int k) {
    // Base edge cases
    if (!head || !head->next || k == 0)
      return head;

    // 1. Calculate length and find tail
    ListNode *tail = head;
    int length = 1;
    while (tail->next) {
      tail = tail->next;
      length++;
    }

    // 2. Connect tail to head to form a cycle
    tail->next = head;

    // 3. Optimize k
    k = k % length;
    int stepsToNewTail = length - k;

    // 4. Traverse to the new tail
    ListNode *newTail = tail;
    while (stepsToNewTail > 0) {
      newTail = newTail->next;
      stepsToNewTail--;
    }

    // 5. Break the cycle and set new head
    ListNode *newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
  }
};