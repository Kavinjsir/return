class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &m, int k) {
    int c = 0, rl = m.size(), cl = m[0].size();

    auto cmp = [](pair<int, int> left, pair<int, int> right) {
      if (left.second > right.second)
        return true;
      if (left.second == right.second && left.first > right.first)
        return true;
      return false;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < rl; i++) {
      c = 0;
      for (int j = 0; j < cl; j++) {
        if (m[i][j] == 0)
          break;
        c++;
      }
      pair<int, int> p(i, c);
      pq.push(p);
    }

    vector<int> res;
    pair<int, int> t;
    while (k > 0) {
      t = pq.top();
      res.push_back(t.first);
      pq.pop();
      k--;
    }

    return res;
  }
};
