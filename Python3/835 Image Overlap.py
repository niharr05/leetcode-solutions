from collections import Counter

class Solution:

    def largestOverlap(
        self, img1: list[list[int]], img2: list[list[int]]
    ) -> int:
        n = len(img1)

        # Gather coordinates of 1s in both images
        ones1 = [
            (r, c) for r in range(n) for c in range(n) if img1[r][c] == 1
        ]
        ones2 = [
            (r, c) for r in range(n) for c in range(n) if img2[r][c] == 1
        ]

        # Frequency map for translation vectors
        vector_counts = Counter()

        # Compute translation vector for every pair of 1s
        for r1, c1 in ones1:
            for r2, c2 in ones2:
                vector_counts[(r2 - r1, c2 - c1)] += 1

        # Return maximum overlap count across all translation vectors
        return max(vector_counts.values()) if vector_counts else 0