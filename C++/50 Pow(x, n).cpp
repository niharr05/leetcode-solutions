class Solution {
public:
  double myPow(double x, int n) {
    long long N = n; // Cast to prevent overflow when n = INT_MIN

    if (N < 0) {
      x = 1 / x;
      N = -N;
    }

    double result = 1.0;
    double current_product = x;

    while (N > 0) {
      // If N is odd, multiply the current base with result
      if (N % 2 == 1) {
        result *= current_product;
      }

      // Square the base and halve the exponent
      current_product *= current_product;
      N /= 2;
    }

    return result;
  }
};