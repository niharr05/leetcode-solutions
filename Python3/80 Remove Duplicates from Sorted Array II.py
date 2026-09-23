class Solution:

    def removeDuplicates(self, nums: list[int]) -> int:
        # Base case: arrays of length 2 or less are already valid
        if len(nums) <= 2:
            return len(nums)

        # Start inserting from index 2
        insert_index = 2

        for i in range(2, len(nums)):
            # Compare current element with the element 2 positions back in the modified array
            if nums[i] != nums[insert_index - 2]:
                nums[insert_index] = nums[i]
                insert_index += 1

        return insert_index