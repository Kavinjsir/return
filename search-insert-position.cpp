class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    
    while (l <= r ) {
      m = (l + r) / 2;
      if (nums[m] == target) return m;
      if (nums[m] < target) l = m + 1;
      else r = m - 1;
    }
    if (nums[m] < target) return m + 1;
    return m;
  }
};
