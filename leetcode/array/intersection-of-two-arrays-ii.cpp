class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> r;
    for (auto c : nums1)
      r[c]++;

    vector<int> s;
    for (auto c : nums2) {
      if (r[c] && r[c] > 0) {
        s.push_back(c);
        r[c]--;
      }
    }
    return s;
  }
};
