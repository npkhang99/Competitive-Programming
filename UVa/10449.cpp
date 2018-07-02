#include <bits/stdc++.h>
using namespace std;

#define cubic(X) (X) * (X) * (X)

typedef pair<int,int> ii;

const int N = 209;
const int LIMIT = 199 * cubic(20);

int n, m, w[N], dist[N] = {}, delta[N] = {};
vector<ii> adj[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 0;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            adj[i].clear();
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(ii(y, cubic(w[y] - w[x])));
        }

        memset(dist, 0x3f, sizeof dist);
        memset(delta, 0x3f, sizeof delta);

        dist[1] = 0;
        for (int i = 0; i < n + 3; i++) {
            for (int u = 1; u <= n; u++) {
                for (int j = 0; j < (int) adj[u].size(); j++) {
                    int v = adj[u][j].first,
                        dv = adj[u][j].second;
                    if (dist[v] > dist[u] + dv) {
                        if (i > n) delta[v] = dist[u] + dv - dist[v];
                        dist[v] = dist[u] + dv;
                    }
                }
            }
        }

        cout << "Set #" << ++T << "\n";

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (dist[x] >= 3 && dist[x] <= LIMIT && delta[x] >= 0) cout << dist[x] << "\n";
            else cout << "?\n";
        }
    }
    return 0;
}
