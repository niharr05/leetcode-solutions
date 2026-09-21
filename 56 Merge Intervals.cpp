#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty())
      return {};

    // 1. Sort intervals by start time
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);

    // 2. Iterate through intervals and merge overlaps
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= merged.back()[1]) {
        // Overlap found: extend the end of the previous interval
        merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
      } else {
        // No overlap: append new interval
        merged.push_back(intervals[i]);
      }
    }

    return merged;
  }
};