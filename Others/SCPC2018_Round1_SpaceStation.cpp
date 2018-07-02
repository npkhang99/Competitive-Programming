#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 200009;

int n, m;

int main() {
    setbuf(stdout, NULL);
    int TC; cin >> TC;
    for (int CASE = 1; CASE <= TC; CASE++) {
        cin >> n >> m;

        vector<int> degree;
        set<ii> edges;

        degree.resize(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            edges.insert(ii(x, y));
            edges.insert(ii(y, x));
            degree[x]++;
            degree[y]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 2) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (degree[u] != 2) continue;

            set<ii>::iterator it = edges.lower_bound(ii(u, 1));
            int v1 = (*it).second,
                v2 = (*(++it)).second;

            if (edges.find(ii(v1, v2)) == edges.end()) continue;

            cnt++;

            edges.erase(ii(u, v1));
            edges.erase(ii(v1, u));

            edges.erase(ii(u, v2));
            edges.erase(ii(v2, u));

            degree[u] -= 2;
            degree[v1]--;
            degree[v2]--;

            if (degree[v1] == 2) q.push(v1);
            if (degree[v2] == 2) q.push(v2);
        }

        cout << "Case #" << CASE << "\n" << n - cnt << "\n";
    }
    return 0;
}
