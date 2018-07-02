#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

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
=======
typedef pair<pair<int,string>, int> Triple;

const int N = 10009;

int n, m, t, ans[N] = {};
Triple a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> m >> t;
        queue<Triple> left_q, right_q;
        for (int i = 0; i < m; i++) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i;
        }

        int c = 0, time = 0;
        string ferry_side = "left";
        while (c < m) {
            if (left_q.empty() && right_q.empty()){
                time = a[c].first;
                if (a[c].second != ferry_side) {
                    ferry_side = a[c].second;
                    time += t;
                }
                while (c < m && a[c].first <= time) {
                    if (a[c].second == "right") {
                        right_q.push(a[c]);
                    } else {
                        left_q.push(a[c]);
                    }
                    c++;
                }
            }

            if (ferry_side == "left") {
                for (int i = 0; i < m && !left_q.empty(); i++) {
                    Triple car = left_q.front();
                    left_q.pop();
                    
                }
            }
        }
>>>>>>> a07f666c6cd0789bb23f49ba332c31bc37039013
    }
    return 0;
}
