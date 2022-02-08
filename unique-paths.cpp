class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> vec(m, vector<int> (n, 0));
      vec[0][0] = 1;
      for(int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j++) {
          if (j - 1 >= 0) {
            vec[i][j] += vec[i][j - 1];
          }
          if (i - 1 >= 0) {
            vec[i][j] += vec[i - 1][j];
          }
        }
      }
      return vec[m - 1][n - 1];
    }
};
