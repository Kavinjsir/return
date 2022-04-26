class Solution {
public:
  int minnode(int n, int keyval[], bool mstset[]) {
    int mini = INT_MAX;
    int mini_index = -1;
    for (int i = 0; i < n; i++) {
      if (mstset[i] == false && keyval[i] < mini) {
        mini = keyval[i], mini_index = i;
      }
    }
    return mini_index;
  }

  int solve(int n, vector<vector<int>> &city) {
    int parent[n];
    int keyval[n];
    bool mstset[n];
    for (int i = 0; i < n; i++) {
      keyval[i] = numeric_limits<int>::max();
      mstset[i] = false;
    }
    parent[0] = -1;
    keyval[0] = 0;
    for (int i = 0; i < n - 1; i++) {
      int u = minnode(n, keyval, mstset);
      mstset[u] = true;
      for (int v = 0; v < n; v++) {
        if (city[u][v] && mstset[v] == false && city[u][v] < keyval[v]) {
          keyval[v] = city[u][v];
          parent[v] = u;
        }
      }
    }
    int cost = 0;
    for (int i = 1; i < n; i++) {
      cost += city[parent[i]][i];
    }
    return cost;
  }

  int minCostConnectPoints(vector<vector<int>> &p) {
    int n = p.size();
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cost[i][j] = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
      }
    }
    return solve(n, cost);
  }
};
