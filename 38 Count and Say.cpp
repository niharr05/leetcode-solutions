#include <string>

class Solution {
public:
  std::string countAndSay(int n) {
    std::string s = "1";

    for (int i = 2; i <= n; ++i) {
      std::string next_s = "";
      int len = s.length();
      int count = 1;

      for (int j = 0; j < len; ++j) {
        // Increment count if current character matches the next
        if (j + 1 < len && s[j] == s[j + 1]) {
          count++;
        } else {
          // Append frequency followed by the character value
          next_s += std::to_string(count) + s[j];
          count = 1; // Reset count for the next sequence
        }
      }

      s = next_s;
    }

    return s;
  }
};