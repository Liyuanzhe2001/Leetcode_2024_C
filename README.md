"# Leetcode_2024_C" 

### 快速幂取模
```c++
int pow(int x, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
```

### priority_queue 自定义比较函数
```c++
struct cmp {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
};
priority_queue<vector<int>, vector<vector<int>>, cmp> q;
```