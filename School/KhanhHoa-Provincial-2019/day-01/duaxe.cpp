#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, a[N] = {};

int main() {
    cin >> n;
    assert(3 <= n && n <= 1000000);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        assert(0 < a[i] && a[i] <= 1000000000);
    }

    long long ans = 0;
    int l = 0, r = 0;
    bool asc = false;
    while (r < n) {
        r += 1;
        if (asc && a[r - 1] > a[r]) {
            l = r - 1;
            asc = false;
            continue;
        }

        if (a[r - 1] < a[r]) {
            if (a[l] < a[r]) {
                ans += a[r] - a[r - 1];
            }
            asc = true;
        }
    }

    cout << ans << endl;
    return 0;
}
