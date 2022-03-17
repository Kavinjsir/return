class Solution {
public:
  int jump(vector<int>& nums) {
    int i = 0, len = nums.size(), steps = 0, reach = 0, maxReach = 0;
    while(reach < len - 1) {
      steps++;
      for (; i <= reach; i++) {
        maxReach = max(maxReach, i + nums[i]);
        if (maxReach >= len - 1) return steps;
      }
      reach = maxReach;
    }
    return steps;
  }
};

