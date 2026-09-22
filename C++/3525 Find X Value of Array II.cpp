#include <vector>

using namespace std;

struct Node {
  int remain[5] = {0};
  int prod = 1;
};

class SegmentTree {
private:
  int n;
  int k;
  vector<Node> tree;

  Node merge(const Node &left, const Node &right) {
    Node node;
    node.prod = (left.prod * right.prod) % k;

    // Prefixes contained entirely within the left child
    for (int i = 0; i < k; ++i) {
      node.remain[i] += left.remain[i];
    }

    // Prefixes that cross over into the right child
    for (int i = 0; i < k; ++i) {
      int new_rem = (i * left.prod) % k;
      node.remain[new_rem] += right.remain[i];
    }

    return node;
  }

  void build(const vector<int> &nums, int cur, int left, int right) {
    if (left == right) {
      int val = nums[left] % k;
      tree[cur].remain[val] = 1;
      tree[cur].prod = val;
      return;
    }
    int mid = left + (right - left) / 2;
    build(nums, 2 * cur + 1, left, mid);
    build(nums, 2 * cur + 2, mid + 1, right);
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
  }

  void update(int cur, int lo, int hi, int idx, int val) {
    if (lo == hi) {
      for (int j = 0; j < k; ++j) {
        tree[cur].remain[j] = 0;
      }
      int rem = val % k;
      tree[cur].remain[rem] = 1;
      tree[cur].prod = rem;
      return;
    }
    int mid = lo + (hi - lo) / 2;
    if (idx <= mid) {
      update(2 * cur + 1, lo, mid, idx, val);
    } else {
      update(2 * cur + 2, mid + 1, hi, idx, val);
    }
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
  }

  Node query(int cur, int lo, int hi, int ql, int qr) {
    if (ql <= lo && hi <= qr) {
      return tree[cur];
    }
    int mid = lo + (hi - lo) / 2;
    if (qr <= mid) {
      return query(2 * cur + 1, lo, mid, ql, qr);
    }
    if (ql > mid) {
      return query(2 * cur + 2, mid + 1, hi, ql, qr);
    }

    Node left = query(2 * cur + 1, lo, mid, ql, qr);
    Node right = query(2 * cur + 2, mid + 1, hi, ql, qr);
    return merge(left, right);
  }

public:
  SegmentTree(const vector<int> &nums, int k)
      : n(nums.size()), k(k), tree(4 * n) {
    build(nums, 0, 0, n - 1);
  }

  void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

  Node query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }
};

class Solution {
public:
  vector<int> resultArray(vector<int> &nums, int k,
                          vector<vector<int>> &queries) {
    SegmentTree tree(nums, k);
    vector<int> result;
    result.reserve(queries.size());

    for (const auto &q : queries) {
      int idx = q[0];
      int val = q[1];
      int start = q[2];
      int x = q[3];

      // 1. Point update
      tree.update(idx, val);

      // 2. Query range [start, n - 1]
      Node resNode = tree.query(start, nums.size() - 1);
      result.push_back(resNode.remain[x]);
    }

    return result;
  }
};