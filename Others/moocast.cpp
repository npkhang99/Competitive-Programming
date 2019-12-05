// USACO 2016 December Contest, Silver
// Problem 3. Moocast
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 209;

int n;
iii a[N];
vector<int> adj[N];

double dist(ii a, ii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

int bfs(int s) {
    vector<bool> visited(N, false);
    int size = 0;
    queue<int> q;

    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        size += 1;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return size;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        a[i] = iii(ii(x, y), p);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (dist(a[i].first, a[j].first) < a[i].second) {
                adj[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, bfs(i));
    }

    cout << ans << endl;
    return 0;
}
