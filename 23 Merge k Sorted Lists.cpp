#include <queue>
#include <vector>

using namespace std;

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Custom comparator for min-heap ordered by node value
    auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };

    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> minHeap(
        comp);

    // Push the head of each non-empty list into the min-heap
    for (auto list : lists) {
      if (list != nullptr) {
        minHeap.push(list);
      }
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    // Process the min-heap until empty
    while (!minHeap.empty()) {
      ListNode *minNode = minHeap.top();
      minHeap.pop();

      tail->next = minNode;
      tail = tail->next;

      // If the popped node has a next element, push it into the min-heap
      if (minNode->next != nullptr) {
        minHeap.push(minNode->next);
      }
    }

    return dummy.next;
  }
};