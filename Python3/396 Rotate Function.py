class Solution:

    def maxRotateFunction(self, nums: list[int]) -> int:
        n = len(nums)
        total_sum = sum(nums)

        # Compute F(0)
        current_f = sum(i * val for i, val in enumerate(nums))
        max_f = current_f

        # Compute F(1) to F(n-1) iteratively
        for k in range(1, n):
            current_f = current_f + total_sum - n * nums[n - k]
            max_f = max(max_f, current_f)

        return max_f