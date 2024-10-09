#include <bits/stdc++.h>

constexpr int inf32 = (int)(1e9) + 9;

constexpr int N = 20004;

int n, s, t, a[N], f[2][N * 2];

int main() {
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        int o = 0, w = s;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            o = std::max(o, a[i]);
            if (w > a[i]) {
                w -= a[i];
                a[i] = -a[i];
            }
        }
        std::sort(a + 1, a + n + 1);
        for (t = 0; t + 1 <= n && a[t + 1] < 0; t++) ;
        if (t == n) printf("%d\n", s - w);
        else {
            std::fill_n((int*)f[t & 1], N * 2, inf32);
            f[t & 1][N - w] = 0;
            for (int i = t + 1; i <= n; i++) {
                int pre = i - 1 & 1, cur = i & 1;
                std::fill_n((int*)f[cur], N * 2, inf32);
                for (int j = -o; j <= o; j++)
                    f[cur][N + j] = std::min(f[cur][N + j], f[pre][N + j]);
                for (int j = -o; j < 0; j++)
                    f[cur][N + j + a[i]] = std::min(f[cur][N + j + a[i]], f[pre][N + j]);
                for (int j = o; j >= 0; j--)
                    for (int p = f[cur][N + j] + 1; p <= t && p <= f[pre][N + j]; p++)
                        f[cur][N + j + a[p]] = std::min(f[cur][N + j + a[p]], p);
            }
            for (int i = 0; i >= -o; i--) if (f[n & 1][N + i] <= t) {
                printf("%d\n", s + i);
                break;
            }
        }
    }
    return 0;
}