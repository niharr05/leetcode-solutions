class Solution:

    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        # Early exit if s is shorter than t
        if m < n:
            return 0

        # dp[j] stores the number of distinct subsequences matching t[:j]
        dp = [0] * (n + 1)
        dp[0] = 1  # Base case: empty target string t

        for char_s in s:
            # Traverse backwards to use previous step's values
            for j in range(n, 0, -1):
                if char_s == t[j - 1]:
                    dp[j] += dp[j - 1]

        return dp[n]