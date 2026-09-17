#include <algorithm>
#include <vector>

class Solution {
private:
  void backtrack(int index, int target, std::vector<int> &candidates,
                 std::vector<int> &current,
                 std::vector<std::vector<int>> &result) {
    if (target == 0) {
      result.push_back(current);
      return;
    }

    for (int i = index; i < candidates.size(); ++i) {
      // Prune remaining candidates if current candidate exceeds target
      if (candidates[i] > target)
        break;

      // Skip duplicates at the same level of the decision tree
      if (i > index && candidates[i] == candidates[i - 1])
        continue;

      current.push_back(candidates[i]);
      // Pass `i + 1` to ensure each element is used at most once
      backtrack(i + 1, target - candidates[i], candidates, current, result);
      current.pop_back(); // Backtrack
    }
  }

public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    // Sort to group duplicates together and enable early pruning
    std::sort(candidates.begin(), candidates.end());

    backtrack(0, target, candidates, current, result);
    return result;
  }
};