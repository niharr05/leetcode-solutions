#include <cctype>
#include <string>

class Solution {
public:
  bool isNumber(std::string s) {
    bool seenDigit = false;
    bool seenDot = false;
    bool seenExponent = false;

    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];

      if (std::isdigit(c)) {
        seenDigit = true;
      } else if (c == '+' || c == '-') {
        // Sign is only allowed at index 0 or right after an exponent 'e' or 'E'
        if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
          return false;
        }
      } else if (c == 'e' || c == 'E') {
        // Exponent is only allowed if we haven't seen one yet and we have seen
        // a digit prior
        if (seenExponent || !seenDigit) {
          return false;
        }
        seenExponent = true;
        seenDigit = false; // Must see another digit after the exponent
      } else if (c == '.') {
        // Dot is only allowed if we haven't seen a dot or an exponent yet
        if (seenDot || seenExponent) {
          return false;
        }
        seenDot = true;
      } else {
        // Any invalid character
        return false;
      }
    }

    // Valid only if at least one digit was found and satisfied trailing
    // conditions
    return seenDigit;
  }
};