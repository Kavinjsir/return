class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int l = nums.size(), sum = nums[0], maxx = nums[0];

    for (int i = 1; i < l; i++) {
      sum += nums[i];
      if (sum < nums[i])
        sum = nums[i];
      if (maxx < sum)
        maxx = sum;
    }

    return maxx;
  }
};
