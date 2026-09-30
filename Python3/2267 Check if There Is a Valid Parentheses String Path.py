from functools import lru_cache


class Solution:

    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        # Quick pruning
        if (m + n - 1) % 2 != 0:
            return False
        if grid[0][0] == ")" or grid[m - 1][n - 1] == "(":
            return False

        max_possible_balance = (m + n - 1) // 2

        @lru_cache(None)
        def dfs(r: int, c: int, balance: int) -> bool:
            # Update balance for current cell
            if grid[r][c] == "(":
                balance += 1
            else:
                balance -= 1

            # Invalid prefix or exceeds maximum possible open brackets
            if balance < 0 or balance > max_possible_balance:
                return False

            # Base case: reached bottom-right cell
            if r == m - 1 and c == n - 1:
                return balance == 0

            # Explore Down and Right
            res = False
            if r + 1 < m:
                res = res or dfs(r + 1, c, balance)
            if c + 1 < n:
                res = res or dfs(r, c + 1, balance)

            return res

        return dfs(0, 0, 0)