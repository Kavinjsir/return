class Solution {
public:
  string reverseWords(string s) {
    int i = 0, l = s.size();
    auto begin = s.begin();
    for (int j = 0; j < l; ++j) {
      if (s[j] == ' ') {
        reverse(begin + i, begin + j);
        i = j + 1;
      }
    }
    reverse(begin + i, s.end());
    return s;
  }
};
