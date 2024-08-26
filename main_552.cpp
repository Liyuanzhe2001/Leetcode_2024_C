#include "bits/stdc++.h"

using namespace std;

// TODO 552. 学生出勤记录 II

const int MOD = 1'000'000'007;
const int MX = 100'001;

int memo[MX][2][3];

int dfs(int i, int j, int k) {
    if (i == 0) {
        return 1;
    }
    int &res = memo[i][j][k]; // 注意这里是引用
    if (res) {
        return res;
    }
    res = dfs(i - 1, j, 0); // 填 P
    if (j == 0) {
        res = (res + dfs(i - 1, 1, 0)) % MOD; // 填 A
    }
    if (k < 2) {
        res = (res + dfs(i - 1, j, k + 1)) % MOD; // 填 L
    }
    return res;
};

int checkRecord(int n) {
    return dfs(n, 0, 0);
}