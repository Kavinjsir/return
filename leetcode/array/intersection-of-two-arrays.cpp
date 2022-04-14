class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set r(nums1.begin(), nums1.end());
    vector<int> s;
    for (auto c : nums2) {
      if (r.count(c)) {
        s.push_back(c);
        r.erase(c);
      }
    }
    return s;
  }
};
