#include "bits/stdc++.h"

using namespace std;

// TODO 1547. 切棍子的最小成本
int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    ranges::sort(cuts);

    int m = cuts.size();
    vector<vector<int>> f(m, vector<int>(m));
    for (int i = m - 3; i >= 0; i--) {
        for (int j = i + 2; j < m; j++) {
            int res = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                res = min(res, f[i][k] + f[k][j]);
            }
            f[i][j] = res + cuts[j] - cuts[i];
        }
    }
    return f[0][m - 1];
}