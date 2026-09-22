#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minSumOfLengths(std::vector<int> &arr, int target) {
    int n = arr.size();
    std::vector<int> best(n, INT_MAX); // best[i] = min length of sub-array with
                                       // sum = target in arr[0..i]

    int left = 0;
    int current_sum = 0;
    int min_total_length = INT_MAX;
    int current_best = INT_MAX;

    for (int right = 0; right < n; ++right) {
      current_sum += arr[right];

      // Shrink the window if current_sum exceeds target
      while (current_sum > target) {
        current_sum -= arr[left];
        left++;
      }

      // Valid sub-array found ending at `right`
      if (current_sum == target) {
        int current_len = right - left + 1;

        // Check if a non-overlapping valid sub-array exists before `left`
        if (left > 0 && best[left - 1] != INT_MAX) {
          min_total_length =
              std::min(min_total_length, current_len + best[left - 1]);
        }

        current_best = std::min(current_best, current_len);
      }

      // Record the minimum length found up to index `right`
      best[right] = current_best;
    }

    return min_total_length == INT_MAX ? -1 : min_total_length;
  }
};