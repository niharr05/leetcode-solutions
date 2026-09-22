#include <algorithm>
#include <vector>

class Solution {
private:
  void backtrack(int start, std::vector<int> &nums,
                 std::vector<std::vector<int>> &result) {
    // Base case: formed a full permutation
    if (start == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); ++i) {
      // Place nums[i] at position 'start'
      std::swap(nums[start], nums[i]);

      // Recurse for the next position
      backtrack(start + 1, nums, result);

      // Backtrack: restore original array state
      std::swap(nums[start], nums[i]);
    }
  }

public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    backtrack(0, nums, result);
    return result;
  }
};