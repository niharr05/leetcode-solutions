class Solution:

    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        stack = []
        pair = {}

        # Step 1: Pair up corresponding '(' and ')'
        for i, char in enumerate(s):
            if char == "(":
                stack.append(i)
            elif char == ")":
                j = stack.pop()
                pair[i] = j
                pair[j] = i

        # Step 2: Traverse string with direction switching
        result = []
        curr = 0
        step = 1  # 1 for moving right, -1 for moving left

        while curr < n:
            if s[curr] in "()":
                curr = pair[curr]
                step = -step
            else:
                result.append(s[curr])
            curr += step

        return "".join(result)