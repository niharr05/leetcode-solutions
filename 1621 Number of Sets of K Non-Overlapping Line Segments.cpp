class Solution {
private:
  const int MOD = 1e9 + 7;

  // Fast exponentiation for modular inverse: a^(MOD-2) % MOD
  long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
      if (exp % 2 == 1)
        res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp /= 2;
    }
    return res;
  }

  // Modular inverse using Fermat's Little Theorem
  long long modInverse(long long n) { return power(n, MOD - 2); }

public:
  int numberOfSets(int n, int k) {
    long long N = n + k - 1;
    long long R = 2 * k;

    if (R > N)
      return 0;

    // Compute Combination (N choose R) % MOD
    long long num = 1, den = 1;

    for (int i = 0; i < R; ++i) {
      num = (num * (N - i)) % MOD;
      den = (den * (i + 1)) % MOD;
    }

    return (num * modInverse(den)) % MOD;
  }
};