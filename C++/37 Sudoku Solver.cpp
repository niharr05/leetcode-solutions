#include <vector>

class Solution {
private:
  int rows[9] = {0};
  int cols[9] = {0};
  int boxes[9] = {0};

  bool solve(std::vector<std::vector<char>> &board) {
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.') {
          int box_idx = (r / 3) * 3 + (c / 3);

          for (int digit = 0; digit < 9; ++digit) {
            int mask = 1 << digit;

            // Check if digit is available in row, col, and sub-box
            if (!(rows[r] & mask) && !(cols[c] & mask) &&
                !(boxes[box_idx] & mask)) {
              // Place digit and set state
              board[r][c] = '1' + digit;
              rows[r] |= mask;
              cols[c] |= mask;
              boxes[box_idx] |= mask;

              if (solve(board))
                return true;

              // Backtrack: reset digit and clear state
              board[r][c] = '.';
              rows[r] &= ~mask;
              cols[c] &= ~mask;
              boxes[box_idx] &= ~mask;
            }
          }
          return false; // No valid digit found for this cell
        }
      }
    }
    return true; // All cells filled successfully
  }

public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    // Initialize state masks from initial board values
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] != '.') {
          int digit = board[r][c] - '1';
          int mask = 1 << digit;
          int box_idx = (r / 3) * 3 + (c / 3);

          rows[r] |= mask;
          cols[c] |= mask;
          boxes[box_idx] |= mask;
        }
      }
    }

    solve(board);
  }
};