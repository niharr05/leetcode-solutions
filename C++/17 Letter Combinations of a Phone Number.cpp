#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  const vector<string> pad = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void backtrack(const string &digits, int index, string &current,
                 vector<string> &result) {
    // Base case: formed a full combination length matching digits
    if (index == digits.length()) {
      result.push_back(current);
      return;
    }

    string letters = pad[digits[index] - '0'];
    for (char c : letters) {
      current.push_back(c);
      backtrack(digits, index + 1, current, result);
      current.pop_back(); // Undo choice for backtracking
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty())
      return result;

    string current = "";
    backtrack(digits, 0, current, result);
    return result;
  }
};