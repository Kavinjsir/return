class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size(), n = mat[0].size(), p = 0, q = 0;
    if (int(m * n) != int(r * c))
      return mat;
    vector<vector<int>> s(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        s[i][j] = mat[p][q];
        if (q + 1 == n) {
          p++;
          q = 0;
        } else {
          q++;
        }
      }
    }
    return s;
  }
};
