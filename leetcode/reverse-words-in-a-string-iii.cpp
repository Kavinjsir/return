class Solution {
public:
  void reverse(string &str) {
    int n = str.length(), i = 0;
    while (i < n / 2) {
      swap(str[i], str[n - i - 1]);
      i++;
    }
  }

  string reverseWords(string s) {
    istringstream iss(s);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    ostringstream o;
    auto it = tokens.begin();
    if (it != tokens.end()) {
      reverse(*it);
      o << *it++;
      for (; it != tokens.end(); ++it) {
        reverse(*it);
        o << " " << *it;
      }
    }
    return o.str();
  }
};
