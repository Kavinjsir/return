class Solution {
public:
  int maximumTop(vector<int> &nums, int k) {
    int l = nums.size();
    if (l == 0)
      return -1;
    if (l == 1) {
      if (k % 2 == 0)
        return nums[0];
      return -1;
    }
    if (k == 0)
      return nums[0];
    if (k == 1)
      return nums[1];
    if (k == 2) {
      if (l >= 3)
        return max(nums[0], nums[2]);
      return nums[0];
    }

    int max = INT_MIN;
    if (k > l) {
      for (int i = 0; i < l; i++) {
        if (nums[i] > max)
          max = nums[i];
      }
      return max;
    }

    for (int i = 0; i < k - 1; i++) {
      if (nums[i] > max)
        max = nums[i];
    }

    if (k < l && nums[k] > max)
      max = nums[k];
    return max;
  }
};
