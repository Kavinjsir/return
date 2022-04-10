class Solution {
public:
  int calPoints(vector<string> &ops) {
    int l;
    vector<int> r;
    for (auto t : ops) {
      l = r.size() - 1;

      if (t[0] == '+') {
        r.push_back(r[l] + r[l - 1]);
      } else if (t[0] == 'C') {
        r.pop_back();
      } else if (t[0] == 'D') {
        r.push_back(r[l] * 2);
      } else {
        r.push_back(stoi(t));
      }
    }
    return accumulate(r.begin(), r.end(), 0);
  }
};
