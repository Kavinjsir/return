class Solution {
public:
  void swapK(string &s, int l, int r) {
    while (l < r) {
      swap(s[l++], s[r--]);
    }
  }

  string reverseStr(string s, int k) {
    int l = s.length(), i = 0, m = k + k;
    while (i + m < l) {
      swapK(s, i, i + k - 1);
      i += m;
    }
    swapK(s, i, min(l - 1, i + k - 1));
    return s;
  }
};
