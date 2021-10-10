class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    int len = nums.size();
    if (len < 3 || nums[0] > 0) return result;

    int l, r, sum, prevLeft, prevRight;
    for (int i = 0; i < len - 2; i++) {
      if (nums[i] > 0) break;

      if (i > 0 && nums[i] == nums[i - 1]) continue;

      l = i + 1;
      r = len - 1;
      while(l < r) {
        sum = nums[i] + nums[l] + nums[r];
        if (sum < 0) { l++; }
        else if (sum > 0 ) { r--; }
        else {
          result.push_back({nums[i], nums[l], nums[r]});
          prevLeft = nums[l];
          prevRight = nums[r];
          while(l < r && prevLeft == nums[l]) { l++; }
          while(l < r && prevRight == nums[r]) { r--; }
        }
      }
    }
    return result;
  }
};
