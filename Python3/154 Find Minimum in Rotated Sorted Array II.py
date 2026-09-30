class Solution:

    def findMin(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] < nums[right]:
                # Minimum must be at mid or to the left of mid
                right = mid
            elif nums[mid] > nums[right]:
                # Minimum must be to the right of mid
                left = mid + 1
            else:
                # nums[mid] == nums[right]: safely shrink search space from the right
                right -= 1

        return nums[left]