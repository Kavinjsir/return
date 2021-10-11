#include <bits/stdc++.h>
#include <cmath>

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int i, j, k, tmp = INT_MAX - abs(target), len = nums.size(), sum;
    for (i = 0; i < len - 2; i++) {
      for (j = i + 1; j < len - 1; j++) {
        for (k = j + 1; k < len; k++) {
          sum = nums[i] + nums[j] + nums[k];
          if (sum == target) return target;
          if (abs(target - sum)  < abs(target - tmp)) {
            tmp = sum;
          }
        }
      }
    }
    return tmp;
  }
};
