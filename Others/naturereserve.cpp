#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<long long,ii> iii;

const int N = 10009;

int n, m, l, s, w[N] = {}, cnt[N] = {};
long long d[N] = {};

int main() {
    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %d %d", &n, &m, &l, &s);

        vector<int> sources;
        for (int i = 0; i < s; i++) {
            int x; scanf("%d", &x);
            sources.push_back(x);
        }

        vector< vector<ii> > adj(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y, z; scanf("%d %d %d", &x, &y, &z);
            adj[x].push_back(ii(y, z));
            adj[y].push_back(ii(x, z));
        }

        memset(d, 0x3f, sizeof d);
        memset(w, 0x3f, sizeof w);
        priority_queue<iii> q;
        for (int source : sources) {
            d[source] = 0;
            w[source] = 0;
            cnt[source] = 0;
            q.push(iii(0, ii(source, source)));
        }

        long long mst = 0;
        while (!q.empty()) {
            int u = q.top().second.first;
            int source = q.top().second.second;
            long long du = -q.top().first;
            q.pop();
            if (du != d[u]) continue;
            cnt[source]++;
            mst += du;
            for (ii edge : adj[u]) {
                int v = edge.first,
                    dv = edge.second;
                if (d[v] >= du + dv) {
                    w[v] = min(w[v], dv);
                    if (d[v] > du + dv) {
                        d[v] = du + dv;
                        q.push(iii(-d[v], ii(v, source)));
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += w[i];
        }

        for (int source : sources) {
            ans += (cnt[source] - 1) * l;
        }

#ifdef DEBUG
        fprintf(stderr, "%lld\n", mst);
        for (int i = 1; i <= n; i++) {
            fprintf(stderr, "%lld%c", w[i], " \n"[i == n]);
        }
        for (int source : sources) {
            fprintf(stderr, "%d %lld\n", source, cnt[source]);
        }
#endif

        printf("%lld\n", ans);
    }
    return 0;
}
