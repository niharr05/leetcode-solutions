#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      // Check if the left half is strictly sorted
      if (nums[left] <= nums[mid]) {
        // Target lies in the left sorted range
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      // Otherwise, the right half must be sorted
      else {
        // Target lies in the right sorted range
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};