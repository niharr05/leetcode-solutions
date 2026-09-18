#include <algorithm>
#include <cmath>
#include <string>

class Solution {
public:
  int furthestDistanceFromOrigin(std::string moves) {
    int l_count = 0;
    int r_count = 0;
    int blank_count = 0;

    for (char c : moves) {
      if (c == 'L')
        l_count++;
      else if (c == 'R')
        r_count++;
      else
        blank_count++;
    }

    return std::abs(l_count - r_count) + blank_count;
  }
};