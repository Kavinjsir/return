class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int hang[9][10] = {}, lie[9][10] = {}, ge[9][10] = {};
    int val, pos;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        val = board[i][j] - '0';

        if (val == -2)
          continue;

        if (hang[i][val] == 1)
          return false;
        if (lie[j][val] == 1)
          return false;

        pos = (i / 3) * 3 + j / 3;
        if (ge[pos][val] == 1)
          return false;

        hang[i][val] = 1;
        lie[j][val] = 1;
        ge[pos][val] = 1;
      }
    }

    return true;
  }
};
