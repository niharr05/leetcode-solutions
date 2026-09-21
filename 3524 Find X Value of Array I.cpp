#include <vector>

class Solution {
public:
  std::vector<long long> resultArray(std::vector<int> &nums, int k) {
    std::vector<long long> result(k, 0);
    // dp[r] stores the count of subarrays ending at the current position
    // with product modulo k equal to r.
    std::vector<long long> dp(k, 0);

    for (int num : nums) {
      std::vector<long long> next_dp(k, 0);
      int cur_mod = num % k;

      // Option 1: Start a new subarray consisting of only 'num'
      next_dp[cur_mod]++;

      // Option 2: Extend all existing valid subarrays ending at the previous
      // element
      for (int r = 0; r < k; ++r) {
        if (dp[r] > 0) {
          int new_mod = (r * cur_mod) % k;
          next_dp[new_mod] += dp[r];
        }
      }

      // Accumulate counts for the current ending position
      for (int r = 0; r < k; ++r) {
        result[r] += next_dp[r];
      }

      dp = std::move(next_dp);
    }

    return result;
  }
};