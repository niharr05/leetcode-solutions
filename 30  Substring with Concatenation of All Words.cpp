#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    std::vector<int> result;
    if (s.empty() || words.empty())
      return result;

    int wordLen = words[0].length();
    int numWords = words.size();
    int sLen = s.length();
    int totalLen = wordLen * numWords;

    if (sLen < totalLen)
      return result;

    // Count frequency of each target word
    std::unordered_map<std::string, int> wordCount;
    for (const std::string &word : words) {
      wordCount[word]++;
    }

    // Run sliding window for each offset up to wordLen
    for (int i = 0; i < wordLen; ++i) {
      int left = i;
      int right = i;
      int count = 0;
      std::unordered_map<std::string, int> seen;

      while (right + wordLen <= sLen) {
        std::string word = s.substr(right, wordLen);
        right += wordLen;

        if (wordCount.count(word)) {
          seen[word]++;
          count++;

          // Shrink window from the left if word frequency exceeds target count
          while (seen[word] > wordCount[word]) {
            std::string leftWord = s.substr(left, wordLen);
            seen[leftWord]--;
            count--;
            left += wordLen;
          }

          // If window size matches total concatenation length
          if (count == numWords) {
            result.push_back(left);
          }
        } else {
          // Reset window when an invalid word is encountered
          seen.clear();
          count = 0;
          left = right;
        }
      }
    }

    return result;
  }
};