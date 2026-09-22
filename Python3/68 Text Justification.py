class Solution:

    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        res = []
        i = 0
        n = len(words)

        while i < n:
            # Determine how many words fit on current line
            j = i + 1
            words_len = len(words[i])

            while j < n and words_len + len(words[j]) + (j - i) <= maxWidth:
                words_len += len(words[j])
                j += 1

            num_words = j - i
            total_spaces = maxWidth - words_len

            # Case 1: Last line or line contains only 1 word -> Left Justified
            if j == n or num_words == 1:
                line = " ".join(words[i:j])
                line += " " * (maxWidth - len(line))
            else:
                # Case 2: Fully Justified
                base_spaces = total_spaces // (num_words - 1)
                extra_spaces = total_spaces % (num_words - 1)

                line = ""
                for k in range(i, j - 1):
                    line += words[k]
                    # Add base spaces + 1 extra space if available for left gaps
                    spaces_to_add = base_spaces + (
                        1 if (k - i) < extra_spaces else 0
                    )
                    line += " " * spaces_to_add

                line += words[j - 1]  # Append last word without trailing space

            res.append(line)
            i = j  # Move to next line

        return res