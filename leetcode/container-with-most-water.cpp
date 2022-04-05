class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1, m = 0;
    while (l < r) {
      m = max(m, (r - l) * (min(height[l], height[r])));
      if (height[l] < height[r]) {
        while (l + 1 < r && height[l] >= height[l + 1]) {
          l++;
        }
        l++;
      } else {
        while (r - 1 > l && height[r] >= height[r - 1]) {
          r--;
        }
        r--;
      }
    }
    return m;
  }
};
