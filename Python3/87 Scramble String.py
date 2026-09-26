from functools import cache


class Solution:

    @cache
    def isScramble(self, s1: str, s2: str) -> bool:
        # If both strings are identical, they are scrambles of each other
        if s1 == s2:
            return True

        # Quick pruning: if character counts don't match, return False
        if sorted(s1) != sorted(s2):
            return False

        n = len(s1)

        # Try splitting the string at every possible index i
        for i in range(1, n):
            # Case 1: Substrings are NOT swapped
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(
                s1[i:], s2[i:]
            ):
                return True

            # Case 2: Substrings ARE swapped
            if self.isScramble(s1[:i], s2[n - i :]) and self.isScramble(
                s1[i:], s2[: n - i]
            ):
                return True

        return False