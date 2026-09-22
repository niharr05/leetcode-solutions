#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int n = digits.size();

    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits; // No carry required beyond this point
      }
      digits[i] = 0; // Carry over 1 to the next digit left
    }

    // If all digits were 9 (e.g. 999 -> 000), prepend 1 at the front
    digits.insert(digits.begin(), 1);
    return digits;
  }
};