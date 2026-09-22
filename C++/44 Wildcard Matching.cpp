#include <string>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int s_idx = 0, p_idx = 0;
    int star_idx = -1, s_tmp_idx = -1;
    int s_len = s.length(), p_len = p.length();

    while (s_idx < s_len) {
      // Case 1: Direct character match or '?'
      if (p_idx < p_len && (p[p_idx] == '?' || p[p_idx] == s[s_idx])) {
        s_idx++;
        p_idx++;
      }
      // Case 2: Encounter '*' wildcard
      else if (p_idx < p_len && p[p_idx] == '*') {
        star_idx = p_idx;
        s_tmp_idx = s_idx;
        p_idx++; // Try matching empty sequence first
      }
      // Case 3: Mismatch after a previously seen '*' -> Backtrack
      else if (star_idx != -1) {
        p_idx = star_idx + 1;
        s_tmp_idx++;
        s_idx = s_tmp_idx; // '*' consumes one more character
      }
      // Case 4: Mismatch without any '*' to backtrack to
      else {
        return false;
      }
    }

    // Consume remaining trailing '*' characters in pattern
    while (p_idx < p_len && p[p_idx] == '*') {
      p_idx++;
    }

    return p_idx == p_len;
  }
};