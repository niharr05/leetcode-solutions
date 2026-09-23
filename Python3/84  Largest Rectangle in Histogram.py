class Solution:

    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = []  # Stores indices of heights
        max_area = 0

        # Append 0 to flush all elements from the stack at the end
        heights.append(0)

        for i, h in enumerate(heights):
            # Maintain a monotonic increasing stack
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]

                # Calculate width
                width = i if not stack else i - stack[-1] - 1

                max_area = max(max_area, height * width)

            stack.append(i)

        return max_area