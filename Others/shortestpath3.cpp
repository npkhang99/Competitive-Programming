// Kattis -- KTH CSC Popup 2005
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 1009;
const int INF = 1e9;

int n, m, q, s;

int main() {
    while (true) {
        scanf("%d %d %d %d", &n, &m, &q, &s);

        if (n == 0) {
            break;
        }

        vector<int> d(n, INF);
        vector<iii> edges;
        for (int i = 0; i < m; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.push_back(iii(ii(x, y), z));
        }

        d[s] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                int u = edges[j].first.first;
                int v = edges[j].first.second;
                int w = edges[j].second;
                if (d[u] != INF && d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                int u = edges[j].first.first;
                int v = edges[j].first.second;
                int w = edges[j].second;
                if (d[u] != INF && d[v] > d[u] + w) {
                    d[v] = -INF;
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int t;
            scanf("%d", &t);
            if (d[t] == INF) printf("Impossible\n");
            else if (d[t] == -INF) printf("-Infinity\n");
            else printf("%d\n", d[t]);
        }
        printf("\n");
    }
    return 0;
}
