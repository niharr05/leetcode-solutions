class Solution:

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)

        # Length check validation
        if m + n != len(s3):
            return False

        # dp[i][j] will be True if s3[0..i+j-1] is formed by s1[0..i-1] and s2[0..j-1]
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True

        # Base case: s1 only
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]

        # Base case: s2 only
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]

        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                from_s1 = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                from_s2 = dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
                dp[i][j] = from_s1 or from_s2

        return dp[m][n]