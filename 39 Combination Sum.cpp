#include <algorithm>
#include <vector>

class Solution {
private:
  void backtrack(int index, int target, std::vector<int> &candidates,
                 std::vector<int> &current,
                 std::vector<std::vector<int>> &result) {
    // Found a valid combination
    if (target == 0) {
      result.push_back(current);
      return;
    }

    for (int i = index; i < candidates.size(); ++i) {
      // Prune remaining candidates if the current element exceeds target
      if (candidates[i] > target)
        break;

      current.push_back(candidates[i]);
      // Pass `i` (not `i + 1`) to allow using the same element multiple times
      backtrack(i, target - candidates[i], candidates, current, result);
      current.pop_back(); // Backtrack
    }
  }

public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    // Sorting helps with early pruning
    std::sort(candidates.begin(), candidates.end());

    backtrack(0, target, candidates, current, result);
    return result;
  }
};