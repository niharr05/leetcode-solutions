class Solution:

    def setZeroes(self, matrix: list[list[int]]) -> None:
        """Do not return anything, modify matrix in-place instead."""
        m, n = len(matrix), len(matrix[0])
        first_col_zero = False

        # Step 1: Use first row and column as markers
        for r in range(m):
            if matrix[r][0] == 0:
                first_col_zero = True

            for c in range(1, n):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0

        # Step 2: Zero out cells based on markers in first row & column
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0

        # Step 3: Handle the first row
        if matrix[0][0] == 0:
            for c in range(n):
                matrix[0][c] = 0

        # Step 4: Handle the first column
        if first_col_zero:
            for r in range(m):
                matrix[r][0] = 0