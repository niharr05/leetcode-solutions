class Solution:

    def simplifyPath(self, path: str) -> str:
        stack = []

        # Split path by '/' to inspect each directory segment
        parts = path.split("/")

        for part in parts:
            if part == "" or part == ".":
                # Ignore extra slashes and current directory pointers
                continue
            elif part == "..":
                # Move up one directory if possible
                if stack:
                    stack.pop()
            else:
                # Valid directory or file name
                stack.append(part)

        # Reconstruct canonical path
        return "/" + "/".join(stack)