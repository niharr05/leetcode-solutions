#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minMoves(std::vector<std::string> &classroom, int energy) {
    int m = classroom.size();
    int n = classroom[0].size();

    int start_r = -1, start_c = -1;
    std::vector<std::pair<int, int>> litters;

    // Map litter positions to bitmask indices
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (classroom[r][c] == 'S') {
          start_r = r;
          start_c = c;
        } else if (classroom[r][c] == 'L') {
          litters.push_back({r, c});
        }
      }
    }

    int total_litter = litters.size();
    int target_mask = (1 << total_litter) - 1;

    // Visited array: visited[r][c][mask] stores max energy recorded for this
    // state
    std::vector<std::vector<std::vector<int>>> visited(
        m, std::vector<std::vector<int>>(
               n, std::vector<int>(1 << total_litter, -1)));

    // Map (r, c) of litters to index in bitmask
    auto getLitterIndex = [&](int r, int c) {
      for (int i = 0; i < total_litter; ++i) {
        if (litters[i].first == r && litters[i].second == c)
          return i;
      }
      return -1;
    };

    // Queue stores {r, c, mask, energy}
    std::queue<std::tuple<int, int, int, int>> q;

    visited[start_r][start_c][0] = energy;
    q.push({start_r, start_c, 0, energy});

    int moves = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        auto [r, c, mask, e] = q.front();
        q.pop();

        // If all litters collected
        if (mask == target_mask) {
          return moves;
        }

        // Try moving in 4 directions
        for (int d = 0; d < 4; ++d) {
          int nr = r + dirs[d][0];
          int nc = c + dirs[d][1];

          // Check bounds and obstacle
          if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
              classroom[nr][nc] == 'X') {
            continue;
          }

          int next_e = e - 1;
          if (next_e < 0)
            continue; // Out of energy

          // Reset energy if reaching 'R'
          if (classroom[nr][nc] == 'R') {
            next_e = energy;
          }

          int next_mask = mask;
          if (classroom[nr][nc] == 'L') {
            int idx = getLitterIndex(nr, nc);
            if (idx != -1) {
              next_mask |= (1 << idx);
            }
          }

          // Only visit state if achieving strictly higher remaining energy
          if (next_e > visited[nr][nc][next_mask]) {
            visited[nr][nc][next_mask] = next_e;
            q.push({nr, nc, next_mask, next_e});
          }
        }
      }
      moves++;
    }

    return -1; // Unreachable
  }
};