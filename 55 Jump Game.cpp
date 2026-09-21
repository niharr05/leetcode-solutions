#include <algorithm>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int maxReach = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      // If current index is beyond the farthest reachable point, return false
      if (i > maxReach) {
        return false;
      }

      // Update the maximum index we can reach
      maxReach = std::max(maxReach, i + nums[i]);

      // Early exit if we can already reach the last index
      if (maxReach >= n - 1) {
        return true;
      }
    }

    return true;
  }
};