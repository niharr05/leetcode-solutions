#include <climits>
#include <cmath>

class Solution {
public:
  int divide(int dividend, int divisor) {
    // Edge case: overflow handling
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    // Determine sign of the result
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Convert to absolute values using 64-bit long long to avoid overflow
    long long absDividend = std::abs((long long)dividend);
    long long absDivisor = std::abs((long long)divisor);

    long long quotient = 0;

    // Exponential subtraction using bit manipulation
    while (absDividend >= absDivisor) {
      long long tempDivisor = absDivisor;
      long long multiple = 1;

      // Double the divisor until it exceeds absDividend
      while (absDividend >= (tempDivisor << 1)) {
        tempDivisor <<= 1;
        multiple <<= 1;
      }

      // Subtract the chunk and add to quotient
      absDividend -= tempDivisor;
      quotient += multiple;
    }

    return isNegative ? -quotient : quotient;
  }
};