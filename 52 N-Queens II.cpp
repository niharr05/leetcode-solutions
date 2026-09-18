#include <vector>

class Solution {
private:
  int count = 0;
  std::vector<bool> cols;
  std::vector<bool> diag1; // row - col + n - 1
  std::vector<bool> diag2; // row + col

  void backtrack(int row, int n) {
    if (row == n) {
      count++;
      return;
    }

    for (int col = 0; col < n; ++col) {
      int d1 = row - col + n - 1;
      int d2 = row + col;

      if (cols[col] || diag1[d1] || diag2[d2]) {
        continue;
      }

      // Place queen
      cols[col] = diag1[d1] = diag2[d2] = true;

      backtrack(row + 1, n);

      // Backtrack
      cols[col] = diag1[d1] = diag2[d2] = false;
    }
  }

public:
  int totalNQueens(int n) {
    count = 0;
    cols.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);

    backtrack(0, n);

    return count;
  }
};