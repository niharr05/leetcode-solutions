class Solution:

    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        cols = len(matrix[0])
        heights = [0] * cols
        max_area = 0

        # Helper function from LeetCode 84: Largest Rectangle in Histogram
        def max_histogram_area(heights_list: list[int]) -> int:
            stack = []
            max_h_area = 0
            # Make a copy to avoid mutating the outer heights list when appending 0
            h_copy = heights_list + [0]

            for i, h in enumerate(h_copy):
                while stack and h_copy[stack[-1]] > h:
                    height = h_copy[stack.pop()]
                    width = i if not stack else i - stack[-1] - 1
                    max_h_area = max(max_h_area, height * width)
                stack.append(i)

            return max_h_area

        # Process matrix row by row
        for row in matrix:
            for c in range(cols):
                # Build histogram: increment height if '1', reset if '0'
                heights[c] = heights[c] + 1 if row[c] == "1" else 0

            max_area = max(max_area, max_histogram_area(heights))

        return max_area