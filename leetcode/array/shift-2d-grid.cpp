class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> fog(m, vector<int>(n));
    k = k % (m * n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int jt = (j + k) % n;
        int it = (i + (j + k) / n) % m;

        fog[it][jt] = grid[i][j];
      }
    }
    return fog;
  }
};
