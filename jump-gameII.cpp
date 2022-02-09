class Solution {
public:
  int jump(vector<int>& nums) {
    int len = nums.size();
    vector<int> m(len, INT_MAX - 1);
    m[0] = 0;
    
    for (int i = 0; i < len; i++) {
      int range = nums[i];
      
      for (int j = 1; j <= range; j++) {
        if (i + j >= len) break;
        
        m[i + j] = min(m[i + j], m[i] + 1);
      }
    }
    
    return m[len - 1];
  }
};

