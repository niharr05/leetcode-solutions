class Solution:

    def minOperations(self, grid: list[list[int]], x: int) -> int:
        # Flatten the 2D grid into a 1D list
        arr = [val for row in grid for val in row]

        remainder = arr[0] % x

        # Check if all numbers share the same remainder modulo x
        for num in arr:
            if num % x != remainder:
                return -1

        # Sort to locate the median element
        arr.sort()
        median = arr[len(arr) // 2]

        # Calculate the total number of operations
        return sum(abs(num - median) // x for num in arr)