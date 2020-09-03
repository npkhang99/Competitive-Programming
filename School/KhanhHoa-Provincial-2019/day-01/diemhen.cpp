#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,int> ii;

const long long INF = 1'000'000ll * 200'000;
const int N = 100'009;

int n, m, k;
long long dist_from_a[N] = {};
long long dist_from_b[N] = {};
vector<ii> adj[N] = {};

void dijkstra(long long dist[], int s) {
    priority_queue<ii> q;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    q.push(ii(0, s));
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        long long du = -q.top().first;
        q.pop();
        
        if (du != dist[u]) {
            continue;
        }

        for (ii e : adj[u]) {
            int v = e.second;
            long long w = e.first;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(ii(-dist[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    assert(2 <= n && n <= 100'000);
    assert(1 <= m && m <= 200'000);
    assert(1 <= k && k <= 100);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(w, v));

        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(1 <= w && w <= 1'000'000);
    }

    dijkstra(dist_from_a, 1);
    dijkstra(dist_from_b, n);

    for (int q = 0; q < k; q++) {
        long long a, b;
        cin >> a >> b;

        assert(1 <= a && a <= 1'000'000);
        assert(1 <= b && b <= 1'000'000);

        long long ans = 1'000'000 * INF;
        for (int meeting_point = 1; meeting_point <= n; meeting_point++) {
            if (dist_from_a[meeting_point] == INF || dist_from_b[meeting_point] == INF) {
                continue;
            }
            ans = min(ans, dist_from_a[meeting_point] * a + dist_from_b[meeting_point] * b);
        }

        assert(ans != INF);

        cout << ans << endl;
    }
    return 0;
}
