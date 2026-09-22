#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> maxNumOfSubstrings(std::string s) {
    int n = s.length();
    std::vector<int> first(26, -1), last(26, -1);

    for (int i = 0; i < n; ++i) {
      int ch = s[i] - 'a';
      if (first[ch] == -1)
        first[ch] = i;
      last[ch] = i;
    }

    // Helper function to check and expand a valid range starting at `i`
    auto getValidRight = [&](int i) -> int {
      int right = last[s[i] - 'a'];
      for (int j = i; j <= right; ++j) {
        // If a character inside starts before `i`, invalid range
        if (first[s[j] - 'a'] < i)
          return -1;
        right = std::max(right, last[s[j] - 'a']);
      }
      return right;
    };

    std::vector<std::pair<int, int>> intervals; // {right, left}

    for (int i = 0; i < 26; ++i) {
      if (first[i] != -1) {
        int right = getValidRight(first[i]);
        if (right != -1) {
          intervals.push_back({right, first[i]});
        }
      }
    }

    // Sort intervals by their end points (right boundary)
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::string> result;
    int prev_right = -1;

    // Greedy choice of non-overlapping intervals
    for (const auto &[right, left] : intervals) {
      if (left > prev_right) {
        result.push_back(s.substr(left, right - left + 1));
        prev_right = right;
      }
    }

    return result;
  }
};