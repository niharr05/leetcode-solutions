class Solution:

    def exist(self, board: list[list[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        def dfs(r: int, c: int, idx: int) -> bool:
            # Base Case: matched the entire word
            if idx == len(word):
                return True

            # Out of bounds or character mismatch
            if (
                r < 0
                or r >= rows
                or c < 0
                or c >= cols
                or board[r][c] != word[idx]
            ):
                return False

            # Mark cell as visited
            temp = board[r][c]
            board[r][c] = "#"

            # Search in all 4 directions (Up, Down, Left, Right)
            found = (
                dfs(r + 1, c, idx + 1)
                or dfs(r - 1, c, idx + 1)
                or dfs(r, c + 1, idx + 1)
                or dfs(r, c - 1, idx + 1)
            )

            # Backtrack: restore original character
            board[r][c] = temp

            return found

        # Try starting from every cell in the grid
        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True

        return False