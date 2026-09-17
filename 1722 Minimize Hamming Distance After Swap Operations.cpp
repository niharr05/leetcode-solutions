#include <numeric>
#include <unordered_map>
#include <vector>

class DisjointSet {
public:
  std::vector<int> parent;

  DisjointSet(int n) : parent(n) { std::iota(parent.begin(), parent.end(), 0); }

  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]); // Path compression
  }

  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      parent[root_i] = root_j;
    }
  }
};

class Solution {
public:
  int minimumHammingDistance(std::vector<int> &source, std::vector<int> &target,
                             std::vector<std::vector<int>> &allowedSwaps) {
    int n = source.size();
    DisjointSet dsu(n);

    // Build connected components based on allowed swaps
    for (const auto &swap : allowedSwaps) {
      dsu.unite(swap[0], swap[1]);
    }

    // Group element frequencies in `source` by component root ID
    std::unordered_map<int, std::unordered_map<int, int>> component_counts;
    for (int i = 0; i < n; ++i) {
      int root = dsu.find(i);
      component_counts[root][source[i]]++;
    }

    int hamming_distance = 0;

    // Check if `target[i]` can be fulfilled by the available elements in its
    // component
    for (int i = 0; i < n; ++i) {
      int root = dsu.find(i);
      int val = target[i];

      if (component_counts[root][val] > 0) {
        component_counts[root][val]--; // Match found
      } else {
        hamming_distance++; // Mismatch
      }
    }

    return hamming_distance;
  }
};