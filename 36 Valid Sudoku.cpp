#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.')
          continue;

        int val = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
        int mask = 1 << val;
        int box_idx = (r / 3) * 3 + (c / 3);

        // Check for duplicates in row, column, or 3x3 sub-box
        if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
          return false;
        }

        // Mark digit as seen
        rows[r] |= mask;
        cols[c] |= mask;
        boxes[box_idx] |= mask;
      }
    }

    return true;
  }
};