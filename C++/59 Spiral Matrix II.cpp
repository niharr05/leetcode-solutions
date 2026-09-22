#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
      // 1. Move Right across the top row
      for (int col = left; col <= right; ++col) {
        matrix[top][col] = num++;
      }
      top++;

      // 2. Move Down along the right column
      for (int row = top; row <= bottom; ++row) {
        matrix[row][right] = num++;
      }
      right--;

      // 3. Move Left across the bottom row
      if (top <= bottom) {
        for (int col = right; col >= left; --col) {
          matrix[bottom][col] = num++;
        }
        bottom--;
      }

      // 4. Move Up along the left column
      if (left <= right) {
        for (int row = bottom; row >= top; --row) {
          matrix[row][left] = num++;
        }
        left++;
      }
    }

    return matrix;
  }
};