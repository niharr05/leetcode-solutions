from bisect import bisect_right
from functools import lru_cache


class Solution:

    def maximumWeight(self, intervals: list[list[int]]) -> list[int]:
        n = len(intervals)

        # Store intervals as (l, r, weight, original_index) and sort by start time l
        sorted_intervals = sorted(
            (l, r, w, idx) for idx, (l, r, w) in enumerate(intervals)
        )
        starts = [item[0] for item in sorted_intervals]

        # Precompute the next valid non-overlapping interval index
        next_indices = [
            bisect_right(starts, sorted_intervals[i][1]) for i in range(n)
        ]

        @lru_cache(None)
        def dp(k: int, i: int):
            if k == 0 or i == n:
                return (0, ())

            # Option 1: Skip current interval
            best_weight, best_indices = dp(k, i + 1)

            # Option 2: Take current interval
            l, r, w, idx = sorted_intervals[i]
            next_i = next_indices[i]
            sub_weight, sub_indices = dp(k - 1, next_i)

            take_weight = w + sub_weight
            # Ensure indices are kept sorted in ascending order
            take_indices = tuple(sorted((idx,) + sub_indices))

            # Compare Take vs Skip: maximize weight, minimize lexicographical tuple
            if take_weight > best_weight:
                best_weight, best_indices = take_weight, take_indices
            elif take_weight == best_weight:
                best_indices = min(best_indices, take_indices)

            return (best_weight, best_indices)

        return list(dp(4, 0)[1])