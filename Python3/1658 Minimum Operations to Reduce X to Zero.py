class Solution:

    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x

        # Edge cases
        if target < 0:
            return -1
        if target == 0:
            return len(nums)

        left = 0
        current_sum = 0
        max_len = -1

        # Sliding window to find the longest subarray summing to target
        for right in range(len(nums)):
            current_sum += nums[right]

            # Shrink window if the sum exceeds the target
            while current_sum > target and left <= right:
                current_sum -= nums[left]
                left += 1

            # Check if we reached the target sum
            if current_sum == target:
                max_len = max(max_len, right - left + 1)

        return len(nums) - max_len if max_len != -1 else -1