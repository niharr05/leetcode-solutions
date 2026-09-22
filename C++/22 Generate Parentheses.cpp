#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  void backtrack(vector<string> &result, string current, int open, int close,
                 int n) {
    // Base case: string length reaches 2 * n
    if (current.length() == 2 * n) {
      result.push_back(current);
      return;
    }

    // Add an open parenthesis if we haven't used all n open parentheses
    if (open < n) {
      backtrack(result, current + '(', open + 1, close, n);
    }

    // Add a close parenthesis only if it doesn't exceed current open count
    if (close < open) {
      backtrack(result, current + ')', open, close + 1, n);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
  }
};