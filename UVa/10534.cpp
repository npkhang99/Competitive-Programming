#include <iostream>
#include <vector>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int lower_bound(const std::vector<int> &a, int x) {
    int l = 0;
    int r = a.size();
    int pos = r;

    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            pos = mid;
            r = mid;
        }
    }

    return r;
}

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> a;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> tmp;

        // longest increasing subsequence
        std::vector<int> lis(n, 1);
        tmp.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            int p = lower_bound(tmp, a[i]);
            if (p == tmp.size()) {
                tmp.push_back(a[i]);
            }
            else {
                tmp[p] = a[i];
            }

            lis[i] = p + 1;
        }

        tmp.clear();

        // longest decreasing subsequence
        std::vector<int> lds(n, 1);
        tmp.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int p = lower_bound(tmp, a[i]);
            if (p == tmp.size()) {
                tmp.push_back(a[i]);
            }
            else {
                tmp[p] = a[i];
            }

            lds[i] = p + 1;
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(lis[i], lds[i]) * 2 - 1);
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
