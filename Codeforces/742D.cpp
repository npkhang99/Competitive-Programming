#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 1009;
const int INF = 0x3f3f3f3f;

int n, m, w, weight[N] = {}, beauty[N] = {}, head[N] = {}, memo[2 * N][N] = {};
vector<iii> a;
vector<int> adj[N];

void dfs(int u, int root) {
    a[u].first = root;
    for (int v : adj[u]) {
        if (!a[v].first) {
            dfs(v, root);
        }
    }
}

int dp(int p, int w) {
    if (p == 0 || w == 0) {
        return 0;
    }

    if (~memo[p][w]) {
        return memo[p][w];
    }

    if (w < a[p].second.first) {
        return memo[p][w] = dp(p - 1, w);
    }

    return memo[p][w] = max(dp(p - 1, w), dp(head[a[p].first] - 1, w - a[p].second.first) + a[p].second.second);
}

int main() {
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &beauty[i]);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].second.first = weight[i];
        a[i].second.second = beauty[i];
        a[i].first = 0;
    }

    int groups = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i].first) {
            dfs(i, ++groups);
        }
    }

    for (int i = 1; i <= groups; i++) {
        int group_weight = 0, group_beauty = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j].first == i) {
                group_weight += a[j].second.first;
                group_beauty += a[j].second.second;
            }
        }
        a.push_back(iii(i, ii(group_weight, group_beauty)));
    }

    n += groups;

    sort(a.begin() + 1, a.end());
    head[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i].first != a[i - 1].first) {
            head[a[i].first] = i;
        }
    }

    memset(memo, -1, sizeof memo);
    printf("%d\n", dp(n, w));
    return 0;
}
