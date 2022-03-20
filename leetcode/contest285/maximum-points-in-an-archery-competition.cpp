// https://leetcode.com/problems/maximum-points-in-an-archery-competition
class Solution {
public:
  int memo[12][100001];
  int dp(int turn, int restArrows, vector<int> &alice) {
    if (turn == 12 || restArrows <= 0)
      return 0;

    if (memo[turn][restArrows] != -1)
      return memo[turn][restArrows];

    // Get the max score in case bob gives up this turn.
    int maxScore = dp(turn + 1, restArrows, alice);

    if (restArrows - alice[turn] > 0) {
      int scoreNotGiveup =
          dp(turn + 1, restArrows - alice[turn] - 1, alice) + turn;
      maxScore = max(maxScore, scoreNotGiveup);
    }

    memo[turn][restArrows] = maxScore;
    return maxScore;
  }

  vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
    memset(memo, -1, sizeof(memo));
    vector<int> ans(12, 0);
    int remainArrows = numArrows;
    for (int turn = 0; turn < 12; turn++) {
      if (dp(turn, numArrows, aliceArrows) !=
          dp(turn + 1, numArrows, aliceArrows)) {
        ans[turn] = aliceArrows[turn] + 1;
        numArrows -= ans[turn];
        remainArrows -= ans[turn];
      }
    }
    ans[0] += remainArrows;
    return ans;
  }
};
