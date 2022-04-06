class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int l = arr.size();

    long long kMod = 1e9 + 7;
    long long count = 0;

    for (int i = 0; i < l - 2; i++) {
      int rest = target - arr[i], j = i + 1, k = l - 1;
      while (j < k) {
        if (arr[j] + arr[k] == rest) {
          if (arr[j] == arr[k]) {
            count += ((k - j + 1) * (k - j) / 2);
            break;
          }
          int left = 1, right = 1;
          while (j + 1 < k && arr[j] == arr[j + 1]) {
            left++;
            j++;
          }
          while (k - 1 > j && arr[k] == arr[k - 1]) {
            right++;
            k--;
          }
          count += (left * right);
          j++;
          k--;
        } else if (arr[j] + arr[k] < rest) {
          j++;
        } else {
          k--;
        }
      }
    }

    return (count % kMod);
  }
};

/*
class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    long long kMod = 1e9 + 7, count = 0;
    unordered_map<int, int> m;

    int l = arr.size();
    for (int k = 1; k < l; k++) {
      count += m[target - arr[k]];

      for (int j = 0; j < k; j++) {
        m[arr[j] + arr[k]]++;
      }
    }

    return count % kMod;
  }
};
*/
