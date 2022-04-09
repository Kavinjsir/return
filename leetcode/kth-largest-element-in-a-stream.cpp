class KthLargest {
public:
  vector<int> before;
  int size;
  KthLargest(int k, vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int i = 0, l = nums.size();
    while (i < k && i < l) {
      before.push_back(nums[i++]);
    }
    make_heap(before.begin(), before.end(), greater<int>{});
    size = k;
  }

  int add(int val) {
    if (before.size() < size) {
      before.push_back(val);
      make_heap(before.begin(), before.end(), greater<int>{});
    } else if (val > before.front()) {
      before.push_back(val);
      pop_heap(before.begin(), before.end(), greater<int>{});
      before.pop_back();
    }

    return before.front();
  }
};
