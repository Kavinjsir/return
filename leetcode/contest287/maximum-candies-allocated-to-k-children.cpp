class Solution {
public:
  bool check(int amount, vector<int> &c, long long k) {
    if (amount == 0)
      return true;

    long long count = 0;

    for (auto t : c) {
      count += t / amount;
      if (count >= k)
        return true;
    }
    return false;
  }

  int maximumCandies(vector<int> &c, long long k) {
    int l = 0, r = 0;
    for (auto t : c) {
      if (t > r)
        r = t;
    }
    int mid = (l + r) / 2;
    while (l <= r) {
      bool cool = check(mid, c, k);
      if (cool) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
      mid = (l + r) / 2;
    }
    return mid;
  }
};
