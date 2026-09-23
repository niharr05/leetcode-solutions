from collections import Counter


class Solution:

    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        # Map to keep track of all the unique characters in t and their counts
        count_t = Counter(t)

        # Number of unique characters in t that need to be present in the window
        need = len(count_t)
        have = 0

        # Dictionary to keep track of character frequencies in the current window
        window = {}

        res = [-1, -1]
        res_len = float("inf")

        left = 0
        for right in range(len(s)):
            char = s[right]
            window[char] = window.get(char, 0) + 1

            # If the frequency of current char matches its frequency in t, increment have
            if char in count_t and window[char] == count_t[char]:
                have += 1

            # Try shrinking window from the left as long as it remains valid
            while have == need:
                # Update smallest window result
                if (right - left + 1) < res_len:
                    res = [left, right]
                    res_len = right - left + 1

                # Shrink window from the left
                left_char = s[left]
                window[left_char] -= 1
                if (
                    left_char in count_t
                    and window[left_char] < count_t[left_char]
                ):
                    have -= 1

                left += 1

        l, r = res
        return s[l : r + 1] if res_len != float("inf") else ""