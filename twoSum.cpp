class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int rest = target - nums[i];
      for (int j = 0; j < len; j++) {
        if (j != i && nums[j] == rest) {
          res.push_back(i);
          res.push_back(j);
          break;
        }
      }
      if (res.size() == 2) {
        break;
      }
    }
    return res;
  }
};
