class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int m = 0, low = prices[0], l = prices.size(), i = 0;

    while (i < l - 1) {
      while (i + 1 < l && prices[i + 1] <= prices[i]) {
        i++;
      }
      low = prices[i] < low ? min(low, prices[i]);

      while (i + 1 < l && prices[i + 1] >= prices[i]) {
        i++;
      }
      m = max(m, prices[i] - low);
    }

    return m;
  }
};
