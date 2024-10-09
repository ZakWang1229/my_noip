#include <bits/stdc++.h>

constexpr int N = 2003;
constexpr int K = 10004;

int n, k;
std::string str[N], h;
std::bitset<K> set[N];
int f[2][K], z1[K], z2[K];

int main() {
    freopen("4.in", "r", stdin);
    freopen("4.out", "w", stdout);
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) std::cin >> str[i];
    set[n][k] = 1;
    for (int i = n - 1; i >= 0; i--) set[i] = set[i + 1] | set[i + 1] >> str[i + 1].size();
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        auto pre = f[i - 1 & 1], cur = f[i & 1];
        int c = str[i].size();
        std::fill_n(z1, K, 0);
        std::fill_n(z2, K, 0);
        std::fill_n(cur, K, 0);
        for (int j = 2, p = 0; j <= c; j++) {
            z1[j] = j < p + z1[p] ? std::min(z1[j - p + 1], p + z1[p] - j) : 0;
            while (j + z1[j] <= c && str[i][z1[j]] == str[i][j + z1[j] - 1]) z1[j]++;
            if (j + z1[j] > p + z1[p]) p = j;
        }
        z1[1] = c;
        for (int j = 1, p = 0; j <= h.size(); j++) {
            z2[j] = j < p + z2[p] ? std::min(z1[j - p + 1], p + z2[p] - j) : 0;
            while (j + z2[j] <= h.size() && z2[j] + 1 <= c && str[i][z2[j]] == h[j + z2[j] - 1]) z2[j]++;
            if (j + z2[j] > p + z2[p]) p = j;
        }
        const auto len = [&](std::pair<int, int> a) { return a.first + a.second * c; };
        const auto pos = [&](std::pair<int, int> a, int p) { 
            assert(p <= len(a));
            return p <= a.first ? h[p - 1] : str[i][p - a.first - 1]; 
        };
        const auto lcp = [&](std::pair<int, int> a, std::pair<int, int> b) {
            if (a.first > b.first) std::swap(a, b);
            if (!a.second) return a.first;
            int t1 = z2[a.first + 1];
            if (a.first + t1 < b.first) return a.first + t1;
            if (!b.second) return b.first;
            int t2 = z1[b.first - a.first + 1];
            return b.first + t2;
        };
        std::vector<std::pair<int, int>> sta;
        const auto insert = [&](std::pair<int, int> a) {
            if (!sta.size()) {
                sta.push_back(a);
                return;
            }
            int t = lcp(sta.back(), a);
            if (t == len(sta.back())) sta.push_back(a);
            else if (pos(a, t + 1) < pos(sta.back(), t + 1)) {
                while (sta.size() && len(sta.back()) > t) sta.pop_back();
                sta.push_back(a);
            }
        };
        for (int j = 0; j <= k; j++) {
            if (!set[i][j]) continue;
            if (pre[j]) insert({j, 0});
            if (j - c >= 0 && pre[j - c]) insert({j - c, 1});
        }
        h = h.substr(0, sta.back().first) + (sta.back().second ? str[i] : "");
        for (auto [p, t] : sta) cur[p + t * c] = 1;
    }
    printf("%s\n", h.c_str());
    return 0;
}