#include <climits>

class Solution {
public:
  int reverse(int x) {
    int rev = 0;

    while (x != 0) {
      int pop = x % 10;
      x /= 10;

      // Overflow check for positive limits: INT_MAX is 2147483647 (ends in 7)
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        return 0;

      // Underflow check for negative limits: INT_MIN is -2147483648 (ends in
      // -8)
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        return 0;

      rev = rev * 10 + pop;
    }

    return rev;
  }
};