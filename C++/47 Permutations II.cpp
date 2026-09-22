#include <algorithm>
#include <vector>

class Solution {
private:
  void backtrack(std::vector<int> &nums, std::vector<bool> &used,
                 std::vector<int> &current,
                 std::vector<std::vector<int>> &result) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      // Skip already used elements
      if (used[i])
        continue;

      // Skip duplicates: enforce picking duplicate elements in left-to-right
      // order
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;

      used[i] = true;
      current.push_back(nums[i]);

      backtrack(nums, used, current, result);

      // Backtrack
      current.pop_back();
      used[i] = false;
    }
  }

public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::vector<bool> used(nums.size(), false);

    // Sort to bring duplicate elements together
    std::sort(nums.begin(), nums.end());

    backtrack(nums, used, current, result);
    return result;
  }
};