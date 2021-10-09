class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> record;
    map<int, int>::iterator iter;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int rest = target - nums[i];
      iter = record.find(rest);
      if (iter == record.end()) {
        record.insert(map<int, int>::value_type(nums[i], i));
      } else {
        res.push_back(iter->second);
        res.push_back(i);
        break;
      }
    }
    return res;
  }
};
