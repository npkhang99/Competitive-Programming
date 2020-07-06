// https://cses.fi/problemset/task/1094
#include <iostream>
#include <vector>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += std::max(0, a[i - 1] - a[i]);
        if (a[i - 1] > a[i]) {
            a[i] = a[i - 1];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
