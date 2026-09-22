#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for (const std::string &str : strs) {
      std::string sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end());
      anagramMap[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    result.reserve(anagramMap.size());

    for (auto &pair : anagramMap) {
      result.push_back(std::move(pair.second));
    }

    return result;
  }
};