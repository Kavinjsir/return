class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    int memo[1001];
    int l = nums.size(), j = 0, i = 0;
    vector<int> res;

    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < l; i++) {
      if (nums[i] == key) {
        for (int j = i - k; j <= i + k; j++) {
          if (j >= 0 && j < l) {
            memo[j] = 1;
          }
        }
      }
    }
    for (int i = 0; i < l; i++) {
      if (memo[i] == 1) {
        res.push_back(i);
      }
    }
    return res;
  }
};
