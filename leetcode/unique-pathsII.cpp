class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    
    vector<vector<int>> m(row, vector<int>(col, 0));
    if (obstacleGrid[0][0] == 0 ) {
      m[0][0] = 1;
    }
    
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (obstacleGrid[i][j] == 1) {
          continue;
        }

        if (i - 1 >= 0) {
          m[i][j] += m[i - 1][j];
        }
        if (j - 1 >= 0) {
          m[i][j] += m[i][j - 1];
        }
      }
    }
    
    return m[row - 1][col - 1];
  }
};
