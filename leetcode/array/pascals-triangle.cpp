class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r;
    vector<int> one = {1};
    r.push_back(one);
    if (numRows == 1)
      return r;

    vector<int> two = {1, 1};
    r.push_back(two);
    if (numRows == 2)
      return r;

    numRows -= 2;
    int l = r.size() - 1;
    while (numRows > 0) {
      vector<int> n;
      n.push_back(1);
      for (int i = 1; i < r[l].size(); i++) {
        int v = r[l][i] + r[l][i - 1];
        n.push_back(v);
      }
      n.push_back(1);
      r.push_back(n);

      numRows--;
      l = r.size() - 1;
    }
    return r;
  }
};
