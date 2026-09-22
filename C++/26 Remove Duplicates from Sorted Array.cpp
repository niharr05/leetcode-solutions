#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty())
      return 0;

    // k tracks the write position for unique elements
    int k = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
      // Found a new unique element
      if (nums[i] != nums[i - 1]) {
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }
};