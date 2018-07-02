#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int cnt[10] = {};

int main() {
    int TC; scanf("%d", &TC);
    while (TC--) {
        memset(cnt, 0, sizeof cnt);
        int n, m;
        scanf("%d %d", &n, &m);

        queue<ii> q;
        int hi = 1;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            q.push(ii(x, i == m));
            cnt[x]++;
            hi = max(hi, x);
        }

        int t = 0;
        while (!q.empty()) {
            if (q.front().first != hi) {
                q.push(q.front());
                q.pop();
                continue;
            } else {
                t++;
                if (q.front().second != 0) {
                    break;
                }
                q.pop();
                cnt[hi]--;
                while (hi > 0 && cnt[hi] == 0) {
                    hi--;
                }
            }
        }
        printf("%d\n", t);
    }
    return 0;
}
