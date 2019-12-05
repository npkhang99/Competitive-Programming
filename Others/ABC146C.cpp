#include <bits/stdc++.h>
using namespace std;

long long a, b, x;

int d(long long n) {
    int d = 0;
    while (n) {
        d += 1;
        n /= 10ll;
    }
    return d;
}

int main() {
    cin >> a >> b >> x;

    long long ans = 0;
    int l = 1;
    int r = 1000000000;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (a * mid + b * d(mid) <= x) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
