class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0, r = matrix.size() - 1, pos = 0, mid = 0;
    while (l < r) {
      mid = (l + r) / 2;
      if (matrix[mid][0] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    if (matrix[l][0] > target) {
      if (l == 0)
        return false;
      pos = l - 1;
    } else {
      pos = l;
    }

    r = matrix[0].size() - 1, l = 0;

    while (l <= r) {
      mid = (l + r) / 2;
      if (matrix[pos][mid] == target)
        return true;
      if (matrix[pos][mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};
