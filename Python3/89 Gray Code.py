class Solution:

    def grayCode(self, n: int) -> list[int]:
        # Generate all 2^n elements using the Gray code formula
        total_elements = 1 << n  # 2^n
        result = []

        for i in range(total_elements):
            result.append(i ^ (i >> 1))

        return result