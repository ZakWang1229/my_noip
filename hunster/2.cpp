#include <bits/stdc++.h>

constexpr int mod = (int)(1e9) + 7;
constexpr int power(int n, int m) {
    int sum = 1;
    for (; m; m >>= 1, n = 1ll * n * n % mod)
        if (m & 1) sum = 1ll * sum * n % mod;
    return sum;
}

int n, X, Y, Z, f[42][1 << 17];

int main() {
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> X >> Y >> Z;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 0; j < 1 << 17; j++) {
        for (int x = 1; x <= 10; x++) {
            int _j = (j << x | 1 << x - 1) & (1 << 17) - 1;
            if ((_j >> X + Y + Z - 1 & 1) && (_j >> Y + Z - 1 & 1) && (_j >> Z - 1 & 1)) continue;
            f[i][_j] = (f[i][_j] + f[i - 1][j]) % mod;
        }
    }
    int sum = power(10, n);
    for (int mask = 0; mask < 1 << 17; mask++)
        sum = (sum - f[n][mask]) % mod;
    printf("%d\n", (sum + mod) % mod);
    return 0;
}