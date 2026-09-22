#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Sort the array to easily handle duplicates and use two pointers
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
      // Early exit: if smallest element is > 0, sum can never be 0
      if (nums[i] > 0)
        break;

      // Skip duplicate values for the first element
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = n - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          result.push_back({nums[i], nums[left], nums[right]});

          // Skip duplicate values for left and right pointers
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        } else if (sum < 0) {
          left++; // Need a larger sum
        } else {
          right--; // Need a smaller sum
        }
      }
    }

    return result;
  }
};