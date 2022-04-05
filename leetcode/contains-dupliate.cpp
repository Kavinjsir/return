class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> r;
    for (auto i : nums) {
      if (r.count(i)) {
        return true;
      }
      r.insert(i);
    }
    return false;
  }
};
