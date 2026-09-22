#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    // Base case: edge conditions where zigzag sequence doesn't alter string
    // order
    if (numRows == 1 || s.length() <= numRows) {
      return s;
    }

    std::vector<std::string> rows(
        std::min(static_cast<int>(s.length()), numRows));
    int currentRow = 0;
    bool goingDown = false;

    for (char c : s) {
      rows[currentRow] += c;

      // Reverse direction when reaching top or bottom row
      if (currentRow == 0 || currentRow == numRows - 1) {
        goingDown = !goingDown;
      }

      currentRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (const std::string &row : rows) {
      result += row;
    }

    return result;
  }
};