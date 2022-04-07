class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    int l = stones.size(), current = 0, t = 0, s = 0;
    if (l == 0)
      return current;

    priority_queue<int> q;
    for (auto s : stones) {
      q.push(s);
    }

    while (!q.empty()) {
      t = q.top();
      q.pop();
      if (q.empty()) {
        return t;
      }

      s = q.top();
      q.pop();
      t -= s;
      if (q.empty())
        return t;
      if (t != 0)
        q.push(t);
    }

    return q.top();
  }
};
