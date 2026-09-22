class Solution:

    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left, right = 1, x // 2
        ans = 0

        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid

            if square == x:
                return mid
            elif square < x:
                ans = mid  # mid is a valid floor root candidate
                left = mid + 1  # search for a larger integer
            else:
                right = mid - 1  # search in the lower half

        return ans