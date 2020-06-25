#include <bits/stdc++.h>
using namespace std;

struct Query {
    int v, c, d;

    void read() {
        scanf("%d %d %d", &v, &d, &c);
    }
};

const int N = 100009;

int n, m, q, color[N]={}, memo[N]={};
bool filled[N]={};
vector<Query> query;
vector<int> adj[N];

void fill(int u, int d, int c) {
    if(d < 0 || memo[u] >= d) return;

    memo[u] = d;
    if(!filled[u]) {
        color[u] = c;
        filled[u] = true;
    }

    for(int v : adj[u])
        fill(v, d-1, c);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    scanf("%d", &q);
    query.resize(q);
    for(int i = 0; i < q; i++)
        query[i].read();

    reverse(query.begin(), query.end());
    memset(memo, -1, sizeof memo);

    for(Query q : query) {
        if(memo[q.v] >= q.d) continue;
        fill(q.v, q.d, q.c);
        memo[q.v] = q.d;
    }

    for(int i = 1; i <= n; i++)
        printf("%d\n", color[i]);
    return 0;
}
