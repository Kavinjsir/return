class Solution {
public:
  int firstUniqChar(string s) {
    int l = s.size();

    int freq[26] = {};

    for (int i = 0; i < l; i++) {
      freq[s[i] - 'a']++;
    }
    for (int i = 0; i < l; i++) {
      if (freq[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};
