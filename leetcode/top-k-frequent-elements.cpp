typedef pair<int, int> pi;
class Solution {
public:
  struct myComparator {
  public:
    bool operator()(const pi &pi1, const pi &pi2) {
      return pi1.second > pi2.second;
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
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top().first);
      pq.pop();
    }
    return result;
  }
};
