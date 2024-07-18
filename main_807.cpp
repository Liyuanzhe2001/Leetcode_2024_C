#include "bits/stdc++.h"

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> row_max(n), col_max(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row_max[i] = max(row_max[i], grid[i][j]);
            col_max[j] = max(col_max[j], grid[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += min(row_max[i], col_max[j]) - grid[i][j];
        }
    }
    return ans;
}