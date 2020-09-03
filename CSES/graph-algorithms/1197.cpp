#include <iostream>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> ii;

struct edge {
    int u, v, w;
};

int n, m;
long long dist[2509] = {};
bool visited[2509] = {};
bool cycle[2509] = {};
bool found = false;
vector<edge> edges;
vector<ii> adj[2509];

void dfs(int u, vector<int>& path, long long before, long long after) {
    path.push_back(u);
    visited[u] = true;

    for (ii e : adj[u]) {
        int v = e.first;
        int w = e.second;
        if (!cycle[v]) {
            continue;
        }

        if (!visited[v]) {
            dfs(v, path, before, after + w);
            if (found) {
                return;
            }
        }
        else if (after + w < before) {
            path.push_back(v);
            found = true;
            return;
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(ii(b, c));
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (edge e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    bool have_cycle = false;
    for (int i = 0; i < n - 1; i++) {
        for (edge e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.u] = dist[e.v] = -INF;
                cycle[e.v] = true;
                have_cycle = true;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cerr << cycle[i] << endl;
    // }

    if (!have_cycle) {
        cout << "NO" << endl;
    }
    else {
        vector<int> path;
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                dfs(i, path, dist[i], dist[i]);
                if (found) {
                    break;
                }
            }
        }

        bool flag = false;

        cout << "YES" << endl;
        for (int i = 0; i < (int) path.size(); i++) {
            if (path[i] == path.back()) {
                flag = true;
            }

            if (flag) {
                cout << path[i] << " \n"[i == (int) path.size() - 1];
            }
        }
    }
    return 0;
}
