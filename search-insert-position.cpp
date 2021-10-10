class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int i;
    int len = nums.size();
    for (i = 0; i < len; i++) {
      if (nums[i] >= target) {
        break;
      }
    }
    return i;
  }
}; 
