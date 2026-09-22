class Solution:

    def containsCycle(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(r: int, c: int, pr: int, pc: int) -> bool:
            visited[r][c] = True

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                # Stay within bounds and match character
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == grid[r][c]:
                    # Ignore the immediate parent cell we came from
                    if nr == pr and nc == pc:
                        continue

                    # If already visited and not the parent, we found a cycle!
                    if visited[nr][nc]:
                        return True

                    # Recurse for unvisited neighbors
                    if dfs(nr, nc, r, c):
                        return True

            return False

        # Run DFS for all unvisited cells
        for r in range(m):
            for c in range(n):
                if not visited[r][c]:
                    if dfs(r, c, -1, -1):
                        return True

        return False