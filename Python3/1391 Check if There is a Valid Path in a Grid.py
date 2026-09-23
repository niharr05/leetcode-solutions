from collections import deque


class Solution:

    def hasValidPath(self, grid: list[list[int]]) -> bool:
        m, n = len(grid), len(grid[0])

        # Direction mappings for each street type
        # UP: (-1, 0), DOWN: (1, 0), LEFT: (0, -1), RIGHT: (0, 1)
        street_dirs = {
            1: [(0, -1), (0, 1)],  # Left, Right
            2: [(-1, 0), (1, 0)],  # Up, Down
            3: [(0, -1), (1, 0)],  # Left, Down
            4: [(0, 1), (1, 0)],  # Right, Down
            5: [(0, -1), (-1, 0)],  # Left, Up
            6: [(0, 1), (-1, 0)],  # Right, Up
        }

        queue = deque([(0, 0)])
        visited = set([(0, 0)])

        while queue:
            r, c = queue.popleft()

            if r == m - 1 and c == n - 1:
                return True

            current_street = grid[r][c]

            for dr, dc in street_dirs[current_street]:
                nr, nc = r + dr, c + dc

                # Check bounds
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited:
                    neighbor_street = grid[nr][nc]

                    # Compatibility check: neighboring street must connect back
                    # The required direction back to current cell is (-dr, -dc)
                    if (-dr, -dc) in street_dirs[neighbor_street]:
                        visited.add((nr, nc))
                        queue.append((nr, nc))

        return False