#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {
    // Initialize a 1D DP table for the first row with 1s
    std::vector<int> dp(n, 1);

    // Process remaining rows
    for (int r = 1; r < m; ++r) {
      for (int c = 1; c < n; ++c) {
        dp[c] += dp[c - 1];
      }
    }

    return dp[n - 1];
  }
};