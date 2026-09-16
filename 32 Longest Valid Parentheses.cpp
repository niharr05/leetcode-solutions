#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
  int longestValidParentheses(std::string s) {
    std::stack<int> st;
    st.push(-1); // Initial base boundary

    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty()) {
          // Update boundary marker for future valid substrings
          st.push(i);
        } else {
          // Calculate current valid substring length
          maxLength = std::max(maxLength, i - st.top());
        }
      }
    }

    return maxLength;
  }
};