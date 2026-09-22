#include <string>
#include <vector>

class Solution {
public:
  std::string getPermutation(int n, int k) {
    std::vector<int> numbers;
    int fact = 1;

    // Build list of numbers [1..n] and compute (n-1)!
    for (int i = 1; i < n; ++i) {
      fact *= i;
      numbers.push_back(i);
    }
    numbers.push_back(n);

    // Convert k to 0-indexed
    k = k - 1;
    std::string result = "";

    for (int i = 0; i < n; ++i) {
      // Find index of the current digit
      int index = k / fact;
      result += std::to_string(numbers[index]);
      numbers.erase(numbers.begin() + index);

      // Prepare for next iteration
      if (numbers.size() > 0) {
        k %= fact;
        fact /= numbers.size();
      }
    }

    return result;
  }
};