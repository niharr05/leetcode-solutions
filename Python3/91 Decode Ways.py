class Solution:

    def numDecodings(self, s: str) -> int:
        # Base case: string starting with '0' cannot be decoded
        if not s or s[0] == "0":
            return 0

        # prev2 represents dp[i-2], prev1 represents dp[i-1]
        prev2, prev1 = 1, 1

        for i in range(1, len(s)):
            curr = 0

            # Single-digit check
            if s[i] != "0":
                curr += prev1

            # Two-digit check
            two_digit = int(s[i - 1 : i + 1])
            if 10 <= two_digit <= 26:
                curr += prev2

            # If current state yields 0 ways, no valid decodings exist
            if curr == 0:
                return 0

            # Move DP state forward
            prev2, prev1 = prev1, curr

        return prev1