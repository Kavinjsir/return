class Solution {
public:
    bool canJump(vector<int>& nums) {
      int len = nums.size();
      vector<bool> m(len, false);
      
      m[0] = true;
      
      int maxTrueIndex = 0;

      for (int i = 0; i < len; i++) {
        if (m[i] == false) continue;

        int steps = nums[i];
        if (i + steps <= maxTrueIndex) continue;

        maxTrueIndex = i + steps;

        if (maxTrueIndex >= len - 1) return true;

        for (int j = 1; j <= steps; j++) {
          if (i + j >= len) break;

          m[i + j] = true;
        }
      }
      return m[len - 1];
    }
};

