class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int upBd = -1, rtBd = n, dwBd = n, ltBd = -1, k = 1;
    int i = ltBd + 1, j = upBd + 1;
    vector<vector<int>> r(n, vector<int>(n));

    while (k <= n * n) {
      for (j = ltBd + 1; j < rtBd; j++) {
        r[i][j] = k;
        k++;
      }
      upBd++;
      j--;

      for (i = upBd + 1; i < dwBd; i++) {
        r[i][j] = k;
        k++;
      }
      rtBd--;
      i--;

      for (j = rtBd - 1; j > ltBd; j--) {
        r[i][j] = k;
        k++;
      }
      dwBd--;
      j++;

      for (i = dwBd - 1; i > upBd; i--) {
        r[i][j] = k;
        k++;
      }
      ltBd++;
      i++;
    }

    return r;
  }
};
