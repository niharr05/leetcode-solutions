class Solution:

    def uniformArray(self, nums1: list[int]) -> bool:
        min_val = min(nums1)

        # Count how many odd and even numbers exist
        odds = sum(1 for x in nums1 if x % 2 != 0)
        evens = len(nums1) - odds

        # If all are already odd or all are already even
        if odds == len(nums1) or evens == len(nums1):
            return True

        # If the minimum element is odd, we can convert all evens to odds
        return min_val % 2 != 0