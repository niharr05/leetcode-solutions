class Solution:

    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = []

        def backtrack(start: int, current_subset: list[int]):
            # Every combination along the traversal path is a valid subset
            res.append(list(current_subset))

            # Try adding subsequent elements one by one
            for i in range(start, len(nums)):
                current_subset.append(nums[i])
                backtrack(i + 1, current_subset)  # Move to next index
                current_subset.pop()  # Backtrack

        backtrack(0, [])
        return res