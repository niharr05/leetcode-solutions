class Solution:

    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        res = []

        # Continue as long as there are digits to process or a carry remains
        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1

            # Append current digit (0 or 1)
            res.append(str(carry % 2))

            # Move carry over to next place value
            carry //= 2

        # Reverse since we built the result from least to most significant digit
        return "".join(reversed(res))