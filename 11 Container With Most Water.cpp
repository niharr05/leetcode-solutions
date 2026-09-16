#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
      // Container height is limited by the shorter line
      int h = min(height[left], height[right]);
      int width = right - left;

      // Update the maximum area found so far
      max_water = max(max_water, h * width);

      // Move the pointer corresponding to the shorter wall
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return max_water;
  }
};