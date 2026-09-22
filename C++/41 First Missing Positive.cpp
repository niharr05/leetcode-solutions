#include <algorithm>
#include <vector>

class Solution {
public:
  int firstMissingPositive(std::vector<int> &nums) {
    int n = nums.size();

    // Place each number in its correct bucket/index if possible
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }

    // Identify the first missing positive number
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    // If all 1 to n are present, the answer is n + 1
    return n + 1;
  }
};