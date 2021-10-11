class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int tmp = INT_MAX - abs(target);
    
    for (int i = 0; i < nums.size() - 2; i++) {
      int j = i + 1;
      int k = nums.size() - 1;
      
      while(j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) return target;
        
        if (abs(target - sum) < abs(target - tmp)) { tmp = sum; }
        if (sum < target) {
          j++;
        } else {
          k--;
        }
      }
    }
    return tmp;
  }
};
