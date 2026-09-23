class Solution:

    def combine(self, n: int, k: int) -> list[list[int]]:
        res = []

        def backtrack(start: int, current_comb: list[int]):
            # Base Case: found a valid combination of size k
            if len(current_comb) == k:
                res.append(list(current_comb))
                return

            # Pruned Loop: only consider numbers where enough candidates remain
            needed = k - len(current_comb)
            for i in range(start, n - needed + 2):
                current_comb.append(i)
                backtrack(i + 1, current_comb)  # Move to next number
                current_comb.pop()  # Backtrack

        backtrack(1, [])
        return res