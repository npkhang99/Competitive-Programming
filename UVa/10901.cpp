#include <bits/stdc++.h>
using namespace std;

int n, t, m, ans[10009] = {}, a[10009] = {};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> t >> m;
        queue<int> q[2];
        for (int i = 0; i < m; i++) {
            string side;
            cin >> a[i] >> side;
            if (side == "left") q[0].push(i);
            else q[1].push(i);
        }

        int time = 0, ferry_side = 0;
        while (!q[0].empty() || !q[1].empty()) {
            if (q[ferry_side].empty() || q[1 - ferry_side].empty()) {
                if (q[ferry_side].empty()) {
                    ferry_side = 1 - ferry_side;
                    time = max(time, a[q[ferry_side].front()]) + t;
                } else {
                    time = max(time, a[q[ferry_side].front()]);
                }

                for (int i = 0; i < n && !q[ferry_side].empty() && a[q[ferry_side].front()] <= time; i++) {
                    ans[q[ferry_side].front()] = time + t;
                    q[ferry_side].pop();
                }
                ferry_side = 1 - ferry_side;
                time += t;
            } else {
                if (a[q[ferry_side].front()] <= a[q[1 - ferry_side].front()] || a[q[ferry_side].front()] <= time) {
                    time = max(time, a[q[ferry_side].front()]);
                    for (int i = 0; i < n && !q[ferry_side].empty() && a[q[ferry_side].front()] <= time; i++) {
                        ans[q[ferry_side].front()] = time + t;
                        q[ferry_side].pop();
                    }
                    ferry_side = 1 - ferry_side;
                    time += t;
                } else {
                    ferry_side = 1 - ferry_side;
                    time = max(time, a[q[ferry_side].front()]) + t;
                    for (int i = 0; i < n && !q[ferry_side].empty() && a[q[ferry_side].front()] <= time; i++) {
                        ans[q[ferry_side].front()] = time + t;
                        q[ferry_side].pop();
                    }
                    ferry_side = 1 - ferry_side;
                    time += t;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            cout << ans[i] << "\n";
        }
        if (TC != 0) cout << "\n";
    }
    return 0;
}
