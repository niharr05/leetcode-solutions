#include <string>
#include <vector>

class Solution {
private:
  std::vector<std::vector<std::string>> result;
  std::vector<bool> cols;
  std::vector<bool> diag1; // row - col + n - 1
  std::vector<bool> diag2; // row + col

  void backtrack(int row, int n, std::vector<std::string> &board) {
    if (row == n) {
      result.push_back(board);
      return;
    }

    for (int col = 0; col < n; ++col) {
      int d1 = row - col + n - 1;
      int d2 = row + col;

      // Check if placing a queen at (row, col) is valid
      if (cols[col] || diag1[d1] || diag2[d2]) {
        continue;
      }

      // Place queen
      board[row][col] = 'Q';
      cols[col] = diag1[d1] = diag2[d2] = true;

      // Recurse to next row
      backtrack(row + 1, n, board);

      // Backtrack
      board[row][col] = '.';
      cols[col] = diag1[d1] = diag2[d2] = false;
    }
  }

public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    result.clear();
    cols.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);

    std::vector<std::string> board(n, std::string(n, '.'));
    backtrack(0, n, board);

    return result;
  }
};