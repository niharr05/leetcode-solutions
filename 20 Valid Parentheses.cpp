#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matching_bracket = {
        {')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
      // If it's a closing bracket
      if (matching_bracket.count(c)) {
        // Return false if stack is empty or top doesn't match
        if (st.empty() || st.top() != matching_bracket[c]) {
          return false;
        }
        st.pop(); // Valid match found
      } else {
        // If it's an opening bracket, push onto stack
        st.push(c);
      }
    }

    // Valid only if all opened brackets were properly matched and closed
    return st.empty();
  }
};