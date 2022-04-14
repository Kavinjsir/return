class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    int r[1001] = {0};
    for (auto c : nums1)
      r[c]++;

    vector<int> s;
    for (auto c : nums2) {
      if (r[c] > 0) {
        s.push_back(c);
        r[c]--;
      }
    }
    return s;
  }
};
