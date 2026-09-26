class Solution:

    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        # Sort to bring identical numbers together
        nums.sort()
        result = []

        def backtrack(start: int, current_subset: list[int]):
            # Every candidate subset constructed along the path is valid
            result.append(list(current_subset))

            for i in range(start, len(nums)):
                # Skip duplicate elements at the same depth level
                if i > start and nums[i] == nums[i - 1]:
                    continue

                # Include nums[i] in the current subset
                current_subset.append(nums[i])

                # Move on to the next element
                backtrack(i + 1, current_subset)

                # Undo the choice (backtrack)
                current_subset.pop()

        backtrack(0, [])
        return result