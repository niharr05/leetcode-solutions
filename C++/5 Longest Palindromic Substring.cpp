#include <algorithm>
#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    if (s.empty())
      return "";

    int start = 0;
    int maxLen = 0;

    auto expandAroundCenter = [&](int left, int right) {
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
      }
      // Return length of palindrome
      return right - left - 1;
    };

    for (int i = 0; i < s.length(); ++i) {
      int len1 = expandAroundCenter(i, i);     // Odd length palindromes
      int len2 = expandAroundCenter(i, i + 1); // Even length palindromes
      int len = std::max(len1, len2);

      if (len > maxLen) {
        maxLen = len;
        start = i - (len - 1) / 2;
      }
    }

    return s.substr(start, maxLen);
  }
};