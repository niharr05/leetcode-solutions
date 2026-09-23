class Solution:

    def maxPathScore(self, grid: list[list[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])

        # dp[r][c][cost] = max score at (r, c) with exact cost 'cost'
        dp = [[[-1] * (k + 1) for _ in range(n)] for _ in range(m)]

        # Base case: grid[0][0] is guaranteed to be 0 (cost 0, score 0)
        dp[0][0][0] = 0

        for r in range(m):
            for c in range(n):
                for cst in range(k + 1):
                    if dp[r][c][cst] == -1:
                        continue

                    # Try moving Down or Right
                    for dr, dc in [(1, 0), (0, 1)]:
                        nr, nc = r + dr, c + dc

                        if nr < m and nc < n:
                            val = grid[nr][nc]
                            cell_cost = 0 if val == 0 else 1
                            cell_score = val

                            next_cst = cst + cell_cost
                            if next_cst <= k:
                                dp[nr][nc][next_cst] = max(
                                    dp[nr][nc][next_cst],
                                    dp[r][c][cst] + cell_score,
                                )

        # Get the maximum score at destination (m-1, n-1) for any cost <= k
        max_score = max(dp[m - 1][n - 1])
        return max_score