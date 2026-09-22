#include <cctype>
#include <climits>
#include <string>

class Solution {
public:
  int myAtoi(std::string s) {
    int i = 0;
    int n = s.length();

    // Step 1: Skip leading whitespace
    while (i < n && s[i] == ' ') {
      ++i;
    }

    // Step 2: Check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
      sign = (s[i] == '-') ? -1 : 1;
      ++i;
    }

    // Step 3: Convert digits with overflow checks
    long result = 0;
    while (i < n && std::isdigit(s[i])) {
      int digit = s[i] - '0';

      // Step 4: Rounding (clamp to 32-bit signed integer limits)
      if (result > (INT_MAX - digit) / 10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }

      result = result * 10 + digit;
      ++i;
    }

    return static_cast<int>(result * sign);
  }
};