#include <algorithm>
#include <vector>

class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 1D array to track minimum path sums for the current row
    std::vector<int> dp(n, 0);

    // Initialize the first row
    dp[0] = grid[0][0];
    for (int c = 1; c < n; ++c) {
      dp[c] = dp[c - 1] + grid[0][c];
    }

    // Process all remaining rows
    for (int r = 1; r < m; ++r) {
      dp[0] += grid[r][0]; // First cell of a row can only come from above
      for (int c = 1; c < n; ++c) {
        dp[c] = grid[r][c] + std::min(dp[c], dp[c - 1]);
      }
    }

    return dp[n - 1];
  }
};