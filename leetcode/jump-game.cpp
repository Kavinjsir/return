class Solution {
public:
  bool canJump(vector<int>& nums) {
    int len = nums.size();
    
    int maxTrueIndex = nums[0];
    
    int i = 0;
    
    while (i < len && i <= maxTrueIndex) {
      maxTrueIndex = max(i + nums[i], maxTrueIndex);
      if (maxTrueIndex >= len - 1 ) break;       
      i++;
    }
    return maxTrueIndex >= len - 1;
  }
};

