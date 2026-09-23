class Solution:

    def search(self, nums: list[int], target: int) -> bool:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return True

            # Handle duplicates: reduce search space when boundaries match mid
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
                continue

            # Check if left half is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1  # Target is in the left sorted range
                else:
                    left = mid + 1  # Target is in the right range
            # Otherwise, right half must be sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1  # Target is in the right sorted range
                else:
                    right = mid - 1  # Target is in the left range

        return False