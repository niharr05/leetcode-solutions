#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> twoEditWords(std::vector<std::string> &queries,
                                        std::vector<std::string> &dictionary) {
    std::vector<std::string> result;

    for (const std::string &query : queries) {
      for (const std::string &dictWord : dictionary) {
        int diff_count = 0;

        for (int i = 0; i < query.length(); ++i) {
          if (query[i] != dictWord[i]) {
            diff_count++;
            if (diff_count > 2)
              break; // Early exit if more than 2 edits required
          }
        }

        // If word can be matched within <= 2 edits, add to result and check
        // next query
        if (diff_count <= 2) {
          result.push_back(query);
          break;
        }
      }
    }

    return result;
  }
};