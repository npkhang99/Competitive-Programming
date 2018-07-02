#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

#define iii(x,y,z) iii(ii(x,y),z)

const int N = 10009;
const int INF = 0x3f3f3f3f;

int n, m, k, s, t, d_src[N] = {}, d_dst[N] = {};
vector<vector<ii>> adj, rev;
vector<iii> edges;

int dijkstra(int s, vector<vector<ii>> adj, int d[]) {
    priority_queue<ii> q;
    d[s] = 0;
    q.push(ii(0, s));
    while (!q.empty()) {
        int du = -q.top().first;
        int u = q.top().second;
        q.pop();
        if (du > d[u]) continue;
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(ii(-d[v], v));
            }
        }
    }
    return d[0];
}

int main() {
    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
        adj.clear();
        rev.clear();
        adj.resize(n + 1);
        rev.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y, z; scanf("%d %d %d", &x, &y, &z);
            adj[x].push_back(ii(y, z));
            rev[y].push_back(ii(x, z));
        }

        edges.clear();
        for (int i = 0; i < k; i++) {
            int x, y, z; scanf("%d %d %d", &x, &y, &z);
            edges.push_back(iii(x,y,z));
            edges.push_back(iii(y,x,z));
        }

        memset(d_src, 0x3f, sizeof d_src);
        memset(d_dst, 0x3f, sizeof d_dst);

        dijkstra(s, adj, d_src);
        dijkstra(t, rev, d_dst);

        int ans = d_src[t];

        for (iii edge : edges) {
            int u = edge.first.first,
                v = edge.first.second,
                w = edge.second;
            ans = min(ans, d_src[u] + d_dst[v] + w);
        }

        printf("%d\n", ans == d_src[0] ? -1 : ans);
    }
    return 0;
}
