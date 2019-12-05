#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 509;
const int INF = 1e9;

int n, m, dist[N] = {};
vector<ii> adj[N], rev[N];
set<ii> used_edges;

void get_shortest_paths(int v) {
    for (ii edge : rev[v]) {
        int u = edge.first;
        int w = edge.second;
        if (dist[u] + w == dist[v]) {
            used_edges.insert(ii(u, v));
            get_shortest_paths(u);
        }
    }
}

void dijkstra(int s) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    priority_queue<ii> q;
    q.push(ii(0, s));
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        int du = -q.top().first;

        q.pop();

        if (du > dist[u]) {
            continue;
        }

        for (ii edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (used_edges.find(ii(u, v)) != used_edges.end()) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(ii(-dist[v], v)); 
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            adj[i].clear();
            rev[i].clear();
        }

        int s, t;
        cin >> s >> t;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(ii(v, w));
            rev[v].push_back(ii(u, w));
        }

        used_edges.clear();
        dijkstra(s);
        get_shortest_paths(t);

        dijkstra(s);
        int ans = dist[t];

        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}
