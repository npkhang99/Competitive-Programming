#include <bits/stdc++.h>
using namespace std;

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
    }
    return 0;
}
