#include <algorithm>
#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return 0;

    int jumps = 0;
    int cur_end = 0;
    int farthest = 0;

    // Loop up to n - 2 because reaching n - 1 means we're done
    for (int i = 0; i < n - 1; ++i) {
      farthest = std::max(farthest, i + nums[i]);

      // When reaching the boundary of the current jump, trigger the next jump
      if (i == cur_end) {
        jumps++;
        cur_end = farthest;

        // Early exit if the last index is already reachable
        if (cur_end >= n - 1)
          break;
      }
    }

    return jumps;
  }
};