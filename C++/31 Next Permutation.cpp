#include <algorithm>
#include <vector>

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }

    if (i >= 0) {
      // Step 2: Find the element just larger than nums[i] from the right
      int j = n - 1;
      while (nums[j] <= nums[i]) {
        j--;
      }
      // Step 3: Swap pivot and successor
      std::swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the remaining suffix to get the smallest order
    std::reverse(nums.begin() + i + 1, nums.end());
  }
};