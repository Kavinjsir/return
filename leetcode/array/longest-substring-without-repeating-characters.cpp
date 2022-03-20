// https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int last[256];
      memset(last, -1, sizeof(last));
      
      int l = 0, r = -1, res = 0, len = s.size();
      while (r + 1 < len) {
        r++;
        if (last[s[r]] != -1) { l = max(l, last[s[r]] + 1); } 
        res = max(res, r - l + 1);
        last[s[r]] = r;
      }
      return res;
    }
};

/*
 * Another solution with similar performance:
 * 3ms, 6.7MB
**  int lengthOfLongestSubstring(string s) {
**    int m[256];
**    memset(m, -1, sizeof(m));
**
**    int l = 0, r = 0, count = 0, vol = s.size();
**    while (r < vol) {
**      if (m[s[r]] > -1) { l = max(l, m[s[r]] + 1); }
**      count = max(r - l + 1, count);
**      m[s[r]] = r;
**      r++;
**    }
**    return count;
**  }
*/
