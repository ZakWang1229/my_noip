#include <bits/stdc++.h>

constexpr int N = 1000006;
constexpr int mod = (int)(1e9) + 7;

int pow2[N];

int n, m;
char s[N], t[N];
int a[N], b[N], a1[N], b1[N];

int main() {
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) pow2[i] = pow2[i - 1] * 2 % mod;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> s >> t;
        n = std::strlen(s);
        m = std::strlen(t);
        a[n] = 0;
        for (int i = 0, c = 0; i < n; i++) {
            c = (2 * c + (s[i] - '0')) % mod;
            a[n - 1 - i] = c;
        }
        b[m] = 0;
        for (int i = 0, c = 0; i < m; i++) {
            c = (2 * c + (t[i] - '0')) % mod;
            b[m - 1 - i] = c;
        }
        for (int i = 0; i < n; i++) a1[i] = (a[i] - a[i + 1]) % mod;
        for (int i = 0; i < m; i++) b1[i] = (b[i] - b[i + 1]) % mod;
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < std::min(n, m); i++) {
            if (i & 1) {
                c1 = (c1 + 1ll * a1[i] * b[i]) % mod;
                c1 = (c1 + 1ll * a[i] * b1[i]) % mod;
                c1 = (c1 - 1ll * a1[i] * b1[i]) % mod;
            }
            else {
                c2 = (c2 + 1ll * a1[i] * b1[i]) % mod;
            }
        }
        c3 = (1ll * a[0] * b[0] - c1 - c2) % mod;
        printf("%d %d %d\n", (c1 + mod) % mod, (c3 + mod) % mod, (c2 + mod) % mod);
    }
    return 0;
}