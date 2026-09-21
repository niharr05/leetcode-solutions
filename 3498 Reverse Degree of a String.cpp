#include <string>

class Solution {
public:
  int reverseDegree(std::string s) {
    int totalDegree = 0;

    for (int i = 0; i < s.length(); ++i) {
      int stringIndex = i + 1;
      int reverseAlphaVal = 'z' - s[i] + 1;

      totalDegree += stringIndex * reverseAlphaVal;
    }

    return totalDegree;
  }
};