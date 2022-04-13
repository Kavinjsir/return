class Solution {
public:
  int getLiveNeighbours(vector<vector<int>> &curr, int i, int j, int m, int n) {
    int liveNeighbours = 0;
    if (i > 0 && (curr[i - 1][j] == 1 || curr[i - 1][j] == 3))
      liveNeighbours++;
    if (i < m - 1 && (curr[i + 1][j] == 1 || curr[i + 1][j] == 3))
      liveNeighbours++;
    if (j > 0 && (curr[i][j - 1] == 1 || curr[i][j - 1] == 3))
      liveNeighbours++;
    if (j < n - 1 && (curr[i][j + 1] == 1 || curr[i][j + 1] == 3))
      liveNeighbours++;

    if (i > 0 && j > 0 && (curr[i - 1][j - 1] == 1 || curr[i - 1][j - 1] == 3))
      liveNeighbours++;
    if (i > 0 && j < n - 1 &&
        (curr[i - 1][j + 1] == 1 || curr[i - 1][j + 1] == 3))
      liveNeighbours++;
    if (i < m - 1 && j > 0 &&
        (curr[i + 1][j - 1] == 1 || curr[i + 1][j - 1] == 3))
      liveNeighbours++;
    if (i < m - 1 && j < n - 1 &&
        (curr[i + 1][j + 1] == 1 || curr[i + 1][j + 1] == 3))
      liveNeighbours++;

    return liveNeighbours;
  }
  void gameOfLife(vector<vector<int>> &board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int ln = getLiveNeighbours(board, i, j, m, n);
        if (board[i][j] == 0 && ln == 3) {
          board[i][j] = 2;
        } else if (board[i][j] == 1 && (ln < 2 || ln > 3)) {
          board[i][j] = 3;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 3) {
          board[i][j] = 0;
        } else if (board[i][j] == 2) {
          board[i][j] = 1;
        }
      }
    }
  }
};
