#include <bits/stdc++.h>
using namespace std;

const int N = 500009;

long long a[N] = {};
string st;

int main() {
    cin >> st;
    int n = st.length();
    a[0] = 0;
    for (int i = 0, j = 1; i < n; i++, j++) {
        if (st[i] == '<') {
            a[j] = a[j - 1] + 1;
        }
        else {
            a[j] = a[j - 1] - 1;
        }

        if (i > 0 && st[i] != st[i - 1] && a[j - 1] != 0) {
            a[j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] < 0 && a[i - 1] > a[i] && a[i] < a[i + 1]) {
            int offset_left = -a[i];
            int offset_right = 0;
            int left_limit = i;
            int right_limit = i;

            for (int j = i - 1; j >= 0 && st[j] == '>' && a[j] <= a[j + 1] + offset_left; j--) {
                left_limit--;
            }

            if (a[i] + offset_left >= a[i + 1]) {
                offset_right = (a[i] + offset_left) - a[i + 1] + 1;
                for (int j = i + 1; j <= n && st[j - 1] == '<'; j++) {
                    right_limit++;
                }
            }

            for (int j = i; j >= left_limit; j--) {
                a[j] += min((long long) offset_left, a[j + 1] + 1 - a[j]);
            }

            for (int j = i + 1; j <= right_limit; j++) {
                a[j] +=  offset_right;
            }

            i = right_limit;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
