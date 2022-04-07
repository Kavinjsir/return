class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    int l = stones.size(), current = 0;
    if (l == 0)
      return current;

    priority_queue<int> q;
    for (auto s : stones) {
      q.push(s);
    }

    while (!q.empty()) {
      int t = q.top();
      q.pop();
      if (q.empty()) {
        return t;
      }
      int s = q.top();
      q.pop();
      if (s == t) {
        if (q.empty())
          return 0;
        continue;
      };
      q.push(t - s);
    }

    return q.top();
  }
};
