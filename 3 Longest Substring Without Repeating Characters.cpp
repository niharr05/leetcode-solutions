#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    // Track the last seen index of each character (ASCII 0-255)
    std::vector<int> lastSeen(256, -1);

    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
      char currentChar = s[right];

      // If the character was seen inside the current window, move the left
      // pointer
      if (lastSeen[currentChar] >= left) {
        left = lastSeen[currentChar] + 1;
      }

      // Update the last seen index of the character
      lastSeen[currentChar] = right;

      // Update the maximum window length
      maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};