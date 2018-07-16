#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 109;
const double INF = 1e9;
const double EPS = 1e-9;

int n;
ii a[N] = {};
double graph[N][N] = {};

double dist(ii a, ii b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    int tc; scanf("%d", &tc);
    for (int test_case = 1; test_case <= tc; test_case++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].first, &a[i].second);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    graph[i][j] = 0;
                } else if (dist(a[i], a[j]) - 10.0 < EPS) {
                    graph[i][j] = dist(a[i], a[j]);
                } else {
                    graph[i][j] = INF;
                }
            }
        }

        floyd_warshall();

        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, graph[i][j]);
            }
        }

        printf("Case #%d:\n", test_case);
        if (ans < INF) {
            printf("%.4lf\n\n", ans);
        } else {
            printf("Send Kurdy\n\n");
        }
    }
    return 0;
}
