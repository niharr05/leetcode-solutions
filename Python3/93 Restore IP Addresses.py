class Solution:

    def restoreIpAddresses(self, s: str) -> list[str]:
        # An IP address has between 4 and 12 digits
        if len(s) < 4 or len(s) > 12:
            return []

        res = []

        def backtrack(start_idx: int, dots: int, current_parts: list[str]):
            # Base Case: found 4 valid parts
            if dots == 4:
                if start_idx == len(s):
                    res.append(".".join(current_parts))
                return

            # Try 1-digit, 2-digit, and 3-digit segments
            for length in range(1, 4):
                if start_idx + length > len(s):
                    break

                part = s[start_idx : start_idx + length]

                # Check leading zero rule and range <= 255
                if (part == "0" or not part.startswith("0")) and int(
                    part
                ) <= 255:
                    backtrack(
                        start_idx + length, dots + 1, current_parts + [part]
                    )

        backtrack(0, 0, [])
        return res