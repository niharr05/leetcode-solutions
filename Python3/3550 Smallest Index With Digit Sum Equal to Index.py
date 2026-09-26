class Solution:

    def smallestIndex(self, nums: list[int]) -> int:
        for i, val in enumerate(nums):
            # Calculate the sum of digits for nums[i]
            digit_sum = 0
            temp = val
            while temp > 0:
                digit_sum += temp % 10
                temp //= 10

            # Early return as soon as we find the first valid index
            if digit_sum == i:
                return i

        return -1