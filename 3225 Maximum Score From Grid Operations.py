class Solution:

    def maximumScore(self, grid: list[list[int]]) -> int:
        n = len(grid)

        # Precompute column prefix sums: prefix[j][i] = sum of column j from row 0 to i-1
        prefix = [[0] * (n + 1) for _ in range(n)]
        for j in range(n):
            for i in range(n):
                prefix[j][i + 1] = prefix[j][i] + grid[i][j]

        # prevPick[i] = max score ending at prev column with i black cells (with pick state)
        # prevSkip[i] = max score ending at prev column with i black cells (with skip state)
        prevPick = [0] * (n + 1)
        prevSkip = [0] * (n + 1)

        for j in range(1, n):
            currPick = [0] * (n + 1)
            currSkip = [0] * (n + 1)

            for curr in range(n + 1):
                for prev in range(n + 1):
                    if curr > prev:
                        # Current height > previous height: score cells in column j - 1
                        score = prefix[j - 1][curr] - prefix[j - 1][prev]
                        currPick[curr] = max(
                            currPick[curr], prevSkip[prev] + score
                        )
                        currSkip[curr] = max(
                            currSkip[curr], prevSkip[prev] + score
                        )
                    else:
                        # Current height <= previous height: score cells in column j
                        score = prefix[j][prev] - prefix[j][curr]
                        currPick[curr] = max(
                            currPick[curr], prevPick[prev] + score
                        )
                        currSkip[curr] = max(
                            currSkip[curr], prevPick[prev]
                        )

            prevPick, prevSkip = currPick, currSkip

        return max(prevPick)