#include <vector>

class Solution {
private:
  int findBound(const std::vector<int> &nums, int target, bool isFirst) {
    int left = 0;
    int right = nums.size() - 1;
    int bound = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        bound = mid; // Record candidate index
        if (isFirst) {
          right = mid - 1; // Squeeze left to find first occurrence
        } else {
          left = mid + 1; // Squeeze right to find last occurrence
        }
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return bound;
  }

public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int first = findBound(nums, target, true);

    // If target doesn't exist, no need to search for the last boundary
    if (first == -1)
      return {-1, -1};

    int last = findBound(nums, target, false);

    return {first, last};
  }
};