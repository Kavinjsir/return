typedef pair<int, int> pi;
class Solution {
public:
  struct myComparator {
  public:
    bool operator()(const pi &pi1, const pi &pi2) {
      return pi2.second > pi1.second;
    }
  };

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> record;
    for (auto i : nums) {
      record[i]++;
    }
    priority_queue<pi, vector<pi>, myComparator> pq;
    for (const auto &p : record) {
      pq.push(p);
    }

    vector<int> result;
    while (k > 0 && !pq.empty()) {
      pi p = pq.top();
      result.push_back(p.first);
      pq.pop();
      k--;
    }
    return result;
  }
};
