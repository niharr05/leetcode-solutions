class Solution:

    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        ends_with = [0] * 26  # stores count of subsequences ending in 'a'-'z'

        for char in s:
            idx = ord(char) - ord("a")
            # New count for 'char' = 1 (just char itself) + all existing distinct subsequences
            ends_with[idx] = (1 + sum(ends_with)) % MOD

        return sum(ends_with) % MOD