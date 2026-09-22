#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();

    // dp[i][j] indicates if s[0...i-1] matches p[0...j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Initialize empty string matches for patterns with '*' (e.g., "a*",
    // "a*b*")
    for (int j = 2; j <= n; ++j) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 2];
      }
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
          // Direct character match or '.' wildcard
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          // Case 1: Treat '*' as 0 occurrences of the preceding element
          dp[i][j] = dp[i][j - 2];

          // Case 2: Treat '*' as 1 or more occurrences if preceding element
          // matches s[i-1]
          if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        }
      }
    }

    return dp[m][n];
  }
};