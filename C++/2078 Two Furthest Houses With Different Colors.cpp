#include <algorithm>
#include <vector>

class Solution {
public:
  int maxDistance(std::vector<int> &colors) {
    int n = colors.size();
    int maxDist = 0;

    // Check distance from the first house (index 0) moving backwards
    for (int i = n - 1; i >= 0; --i) {
      if (colors[i] != colors[0]) {
        maxDist = std::max(maxDist, i);
        break;
      }
    }

    // Check distance from the last house (index n - 1) moving forwards
    for (int i = 0; i < n; ++i) {
      if (colors[i] != colors[n - 1]) {
        maxDist = std::max(maxDist, (n - 1) - i);
        break;
      }
    }

    return maxDist;
  }
};