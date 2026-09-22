#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<long long> distance(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<long long> arr(n, 0);
    std::unordered_map<int, std::vector<int>> pos_map;

    // Group indices by value
    for (int i = 0; i < n; ++i) {
      pos_map[nums[i]].push_back(i);
    }

    // Process each group of identical elements
    for (auto &[val, vec] : pos_map) {
      int k = vec.size();
      if (k <= 1)
        continue;

      // Total sum of all indices in current group
      long long total_sum = 0;
      for (int idx : vec) {
        total_sum += idx;
      }

      long long left_sum = 0;
      for (int i = 0; i < k; ++i) {
        long long current_idx = vec[i];
        long long right_sum = total_sum - left_sum - current_idx;

        // Left distance sum: i * current_idx - left_sum
        // Right distance sum: right_sum - (k - 1 - i) * current_idx
        long long left_dist = (long long)i * current_idx - left_sum;
        long long right_dist = right_sum - (long long)(k - 1 - i) * current_idx;

        arr[current_idx] = left_dist + right_dist;

        left_sum += current_idx;
      }
    }

    return arr;
  }
};