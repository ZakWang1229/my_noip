#include <bits/stdc++.h>

using R = std::uniform_int_distribution<int>;

constexpr int inf32 = (int)(1e9) + 9;
constexpr int lim = 1000000000;

constexpr int N = 20004;
int T, _a[20004], a[20004], f[2][N * 2];

std::mt19937 rng((std::random_device())());
void data1(int n) {
    int c = lim;
    for (int i = 1; i <= n; i++) a[i] = R(1, 200)(rng);
    printf("%d %d\n", n, c);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
}
void data2(int n) {
    while (1) {
        int t1 = n - 100, t2 = n - 100;
        int c = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i <= t1) {
                _a[i] = R(1, 200 / 11)(rng) * 11;
                c += _a[i];
            }
            else if (i <= t2) _a[i] = R(1, 20)(rng) * 10;
            else _a[i] = R(1, 200)(rng);
            sum += _a[i];
        }
        std::cerr << c << " " << sum << std::endl;
        for (int i = 1; i <= 100; i++) c += R(1, 200)(rng);
        int o = 0, w = c;
        for (int i = 1; i <= n; i++) {
            a[i] = _a[i];
            o = std::max(o, a[i]);
            if (w > a[i]) {
                w -= a[i];
                a[i] = -a[i];
            }
        }
        std::sort(a + 1, a + n + 1);
        int t;
        for (t = 0; t + 1 <= n && a[t + 1] < 0; t++) ;
        if (t < n) {
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
            int ans = 0;
            for (int i = 0; i >= -o; i--) if (f[n & 1][N + i] <= t) {
                ans = -i;
                break;
            }
            if (ans > 1) {
                printf("%d %d\n", n, c);
                for (int i = 1; i <= n; i++) printf("%d%c", _a[i], " \n"[i == n]);
                break;
            }
        }
    }
}

int main() {
    puts("1");
    data2(20000);
    // std::cin >> T;
    // printf("%d\n", T);
    // int n = 20000;
    // while (T--) {
    //     // std::uniform_int_distribution<int> cur(1, n - T);
    //     // int t = cur(rng);
    //     int t = 200;
    //     if (rng() % 10) data2(t);
    //     else data1(t);
    //     n -= t;
    // }
    return 0;
}