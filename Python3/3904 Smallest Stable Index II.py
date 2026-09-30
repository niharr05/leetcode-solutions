class Solution:

    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        # Precompute suffix minimums: suffix_min[i] = min(nums[i...n-1])
        suffix_min = [0] * n
        suffix_min[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(nums[i], suffix_min[i + 1])

        prefix_max = float("-inf")

        # Find the first index where prefix_max - suffix_min <= k
        for i in range(n):
            prefix_max = max(prefix_max, nums[i])
            if prefix_max - suffix_min[i] <= k:
                return i

        return -1