class Solution {
public:
  int digArtifacts(int n, vector<vector<int>> &art, vector<vector<int>> &dig) {
    int grid[1001][1001];
    memset(grid, -1, sizeof(grid));

    int record[100001];
    memset(record, -1, sizeof(record));

    int al = art.size(), dl = dig.size();

    for (int i = 0; i < al; i++) {
      for (int p = art[i][0]; p <= art[i][2]; p++) {
        for (int q = art[i][1]; q <= art[i][3]; q++) {
          grid[p][q] = i;
        }
      }
    }

    for (int j = 0; j < dl; j++) {
      grid[dig[j][0]][dig[j][1]] = -1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > -1) {
          record[grid[i][j]] = 1;
        }
      }
    }
    int count = 0;
    for (int i = 0; i < al; i++) {
      if (record[i] > -1)
        count++;
    }
    return al - count;
  }
};
