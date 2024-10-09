#include <bits/stdc++.h>

int n = 20;
std::mt19937 rng((std::random_device())());

void get(int x) {
    putchar('1');
    x--;
    while (x--) putchar('0' + (rng() & 1));
    putchar('\n');
}

int main() {
    int T;
    std::cin >> T;
    printf("%d\n", T);
    for (int i = 1; i <= 2 * T; i++) {
        std::uniform_int_distribution<int> range(1, std::min(15, n - (2 * T - i)));
        int x = range(rng);
        get(x);
    }
    return 0;
}