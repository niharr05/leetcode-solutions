class Solution:

    def numTrees(self, n: int) -> int:
        # dp[i] stores the number of unique BSTs that can be formed using i nodes
        dp = [0] * (n + 1)

        # Base cases
        dp[0] = 1
        dp[1] = 1

        # Fill DP array for node counts 2 through n
        for nodes in range(2, n + 1):
            for root in range(1, nodes + 1):
                left_subtrees = dp[root - 1]
                right_subtrees = dp[nodes - root]

                dp[nodes] += left_subtrees * right_subtrees

        return dp[n]