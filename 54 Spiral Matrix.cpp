#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty())
      return {};

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    std::vector<int> result;

    while (top <= bottom && left <= right) {
      // 1. Traverse Right
      for (int col = left; col <= right; ++col) {
        result.push_back(matrix[top][col]);
      }
      top++;

      // 2. Traverse Down
      for (int row = top; row <= bottom; ++row) {
        result.push_back(matrix[row][right]);
      }
      right--;

      // 3. Traverse Left
      if (top <= bottom) {
        for (int col = right; col >= left; --col) {
          result.push_back(matrix[bottom][col]);
        }
        bottom--;
      }

      // 4. Traverse Up
      if (left <= right) {
        for (int row = bottom; row >= top; --row) {
          result.push_back(matrix[row][left]);
        }
        left++;
      }
    }

    return result;
  }
};