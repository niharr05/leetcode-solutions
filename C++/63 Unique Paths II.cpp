#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // If the start or end cell has an obstacle, no paths exist
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
      return 0;
    }

    // Use long long to handle potential overflow during intermediate DP states
    std::vector<long long> dp(n, 0);
    dp[0] = 1;

    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (obstacleGrid[r][c] == 1) {
          dp[c] = 0; // Dead end
        } else if (c > 0) {
          dp[c] += dp[c - 1]; // Sum paths from left and above
        }
      }
    }

    return dp[n - 1];
  }
};